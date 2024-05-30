#include <iostream>
#include <vector>
#include <filesystem>
#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include <Add_Plugin.hpp>
#include <Main_plugin.hpp>

using namespace std;
namespace fs = filesystem;
typedef Add_Plugin *(*maker_add_plugin)();

Main_plugin::Main_plugin() {
    void * plibobj;
    string func;
    func = "make_add_plugin";
    fs::path filepath = path;
    if(fs::is_directory(filepath.parent_path())) {
        for (const auto & entry : fs::directory_iterator(filepath.parent_path())) {
            plibobj = dlopen(entry.path().c_str(), RTLD_LAZY);
            // If there is an error, output it and exit
            if (!plibobj) {
                cerr << "Error loading the library " << entry.path() << " - " << dlerror() << "\n";
            } else {
                // Here we get the pointer of our target function, it is just a pointer to an undefined object
                maker_add_plugin psqr = (maker_add_plugin)dlsym(plibobj, "make_add_plugin");
                
                // Again, if there is an error accessing the symbol, output it and exit
                if (psqr == NULL) {
                    cerr << "Error accessing the symbol:" << func << dlerror() << "\n";
                } else {
                    Add_Plugin* add_plugin = psqr();
                    all_plugin.push_back(add_plugin);
                }
            }
            //dlclose(plibobj);
        }
    }
}

vector<Add_Plugin*> Main_plugin::getPlugins(){
    return all_plugin;
}


