#ifndef MAIN_PLUGIN_H
#define MAIN_PLUGIN_H

#include <AddPluginInterface.hpp>
#include <string>
#include <vector>
#include <dlfcn.h>

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
		void * plibobj;
};

#endif