#include <iostream>
#include <vector>
#include <filesystem>
#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include <AddPluginInterface.hpp>
#include <Main_plugin.hpp>

using namespace std;
namespace fs = filesystem;
typedef AddPluginInterface *(*maker_AddPluginInterface)();

Main_plugin::Main_plugin() {
    void * plibobj;
    string func;
    func = "make_AddPluginInterface";
    fs::path filepath = path;
    if(fs::is_directory(filepath.parent_path())) {
        for (const auto & entry : fs::directory_iterator(filepath.parent_path())) {
            plibobj = dlopen(entry.path().c_str(), RTLD_LAZY);
            // If there is an error, output it and exit
            if (!plibobj) {
                cerr << "Error loading the library " << entry.path() << " - " << dlerror() << "\n";
            } else {
                // Here we get the pointer of our target function, it is just a pointer to an undefined object
                maker_AddPluginInterface psqr = (maker_AddPluginInterface)dlsym(plibobj, "make_AddPluginInterface");
                
                // Again, if there is an error accessing the symbol, output it and exit
                if (psqr == NULL) {
                    cerr << "Error accessing the symbol:" << func << dlerror() << "\n";
                } else {
                    AddPluginInterface* AddPluginInterface = psqr();
                    all_plugin.push_back(AddPluginInterface);
                }
            }
            //dlclose(plibobj);
        }
    }
}

vector<AddPluginInterface*> Main_plugin::getPlugins(){
    return all_plugin;
}


