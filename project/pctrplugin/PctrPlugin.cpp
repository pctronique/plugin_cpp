#include <iostream>
#include <vector>
#include <filesystem>
#include <stdio.h>
#include <stdlib.h>
#ifdef _WIN32
    #include <windows.h>
#else
    #include <dlfcn.h>
#endif
#include <PctrPlugin.hpp>

#ifdef _WIN32
    HINSTANCE plibobj;
#else
    void* plibobj;
#endif

using namespace std;
namespace fs = filesystem;
typedef void* (*maker_Plugin)();

PctrPlugin::PctrPlugin(string nameInterf) {
    nameInterfLd = nameInterf;
}

PctrPlugin PctrPlugin::loadPlugins(string folder) {
    string func;
    func = "make_"+nameInterfLd;
    if(folder.c_str() != NULL && folder != "") {
        path = folder;
    }
    fs::path filepath = path;
    if(fs::is_directory(filepath.parent_path())) {
        for (const auto & entry : fs::directory_iterator(filepath.parent_path())) {
            #ifdef _WIN32
                plibobj = LoadLibrary(LPCSTR(entry.path().c_str()));
            #else
                plibobj = dlopen(entry.path().c_str(), RTLD_LAZY|RTLD_GLOBAL|RTLD_LOCAL);
            #endif
            // If there is an error, output it and exit
            if (plibobj == NULL) {
                #ifdef _WIN32
                    cerr << "Error loading the library " << entry.path() << "\n";
                #else
                    cerr << "Error loading the library " << entry.path() << " - " << dlerror() << "\n";
                #endif
            } else {
                // Here we get the pointer of our target function, it is just a pointer to an undefined object
                #ifdef _WIN32
                    maker_Plugin psqr = (maker_Plugin)GetProcAddress(plibobj, func.c_str());
                #else
                    maker_Plugin psqr = (maker_Plugin)dlsym(plibobj, func.c_str());
                #endif
                
                // Again, if there is an error accessing the symbol, output it and exit
                if (psqr == NULL) {
                    #ifdef _WIN32
                        cerr << "Error accessing the symbol:" << func.c_str() << "\n";
                    #else
                        cerr << "Error accessing the symbol:" << func.c_str() << dlerror() << "\n";
                    #endif
                } else {
                    void* pluginOne = psqr();
                    all_plugin.push_back(pluginOne);
                }
            }
        }
    }
    return *this;
}

void PctrPlugin::closeLoad() {
    if(plibobj != NULL) {
        #ifdef _WIN32
            FreeLibrary(plibobj);
        #else
            dlclose(plibobj);
        #endif
    }
}

vector<void*> PctrPlugin::getPlugins(){
    return all_plugin;
}
