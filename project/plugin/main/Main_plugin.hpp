#ifndef MAIN_PLUGIN_H
#define MAIN_PLUGIN_H

#include <AddPluginInterface.hpp>
#include <string>
#include <vector>
#ifdef _WIN32
    #include <windows.h>
#else
    #include <dlfcn.h>
#endif

using namespace std;

class Main_plugin
{
	public:
		Main_plugin(){};
		Main_plugin loadPlugins(string folder = "");
		vector<AddPluginInterface *> getPlugins();
	private:
		vector<AddPluginInterface *> all_plugin;
		string path = "./plugins/";
		#ifdef _WIN32
			FARPROC plibobj;
		#else
			void* plibobj;
		#endif
};

#endif