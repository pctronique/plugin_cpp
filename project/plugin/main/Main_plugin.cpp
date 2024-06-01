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
#include <AddPluginInterface.hpp>
#include <Main_plugin.hpp>

using namespace std;
namespace fs = filesystem;
typedef AddPluginInterface *(*maker_AddPluginInterface)();

Main_plugin Main_plugin::loadPlugins(string folder) {
	#ifdef _WIN32
		FARPROC plibobj;
	#else
		void* plibobj;
	#endif
    string func;
    func = "make_AddPluginInterface";
    if(folder.c_str() != NULL && folder != "") {
        path = folder;
    }
    fs::path filepath = path;
    if(fs::is_directory(filepath.parent_path())) {
        for (const auto & entry : fs::directory_iterator(filepath.parent_path())) {
            #ifdef _WIN32
                plibobj = LoadLibrary(TEXT(entry.path().c_str()));
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
                    maker_AddPluginInterface psqr = (maker_AddPluginInterface)GetProcAddress(plibobj, "make_AddPluginInterface");
                #else
                    maker_AddPluginInterface psqr = (maker_AddPluginInterface)dlsym(plibobj, "make_AddPluginInterface");
                #endif
                
                // Again, if there is an error accessing the symbol, output it and exit
                if (psqr == NULL) {
                    #ifdef _WIN32
                        cerr << "Error accessing the symbol:" << func << "\n";
                    #else
                        cerr << "Error accessing the symbol:" << func << dlerror() << "\n";
                    #endif
                } else {
                    AddPluginInterface* addPluginInterface = psqr();
                    all_plugin.push_back(addPluginInterface);
                }
            }
            #ifdef _WIN32
                FreeLibrary(plibobj);
            #else
                dlclose(plibobj);
            #endif
            //dlclose(plibobj);
        }
    }
    return *this;
}

vector<AddPluginInterface*> Main_plugin::getPlugins(){
    return all_plugin;
}


