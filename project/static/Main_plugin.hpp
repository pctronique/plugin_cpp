#ifndef MAIN_PLUGIN_H
#define MAIN_PLUGIN_H

#include <AddPluginInterface.hpp>
#include <string>
#include <vector>

using namespace std;

class Main_plugin
{
	public:
		Main_plugin();
		vector<AddPluginInterface*> getPlugins();
	private:
		vector<AddPluginInterface*> all_plugin;
		string path = "./plugins/";
};

#endif