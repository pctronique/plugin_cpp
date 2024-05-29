#include <iostream>
#include <string>
#include <vector>
#include <filesystem>
#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include <Add_Plugin.hpp>
#include <Main_plugin.hpp>

using namespace std;
namespace fs = filesystem;

Main_plugin::Main_plugin() {
    void * plibobj;
    string func;
    func = "getName";
    fs::path filepath = path;
    if(fs::is_directory(filepath.parent_path())) {
        for (const auto & entry : fs::directory_iterator(path)) {
            bool noterror = true;
            cout << entry.path() << "\n";
            plibobj = dlopen(entry.path().c_str(), RTLD_LAZY);
            // If there is an error, output it and exit
            if (!plibobj) {
                cerr << "Error loading the library " << entry.path() << " - " << dlerror() << "\n";
                noterror = false;
            }
            //Clear any error
            dlerror();

            if(noterror) {
                // Here we get the pointer of our target function, it is just a pointer to an undefined object
                void * psqr =  dlsym(plibobj, func.c_str()) ;
                
                // Again, if there is an error accessing the symbol, output it and exit
                if (psqr == NULL) {
                    cerr << "Error accessing the symbol:" << func << dlerror() << "\n";
                    exit(EXIT_FAILURE);
                } else {
                    Add_Plugin* add_plugin = reinterpret_cast<decltype(add_plugin)>(psqr);
                    all_plugin.push_back(add_plugin);
                }
            }


            /*all_plugin.push_back(buf);
            cout << entry.path().filename() << endl;*/
        }
    }
}

vector<Add_Plugin*> Main_plugin::getPlugins(){
    return all_plugin;
}


