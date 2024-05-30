#ifndef MAIN_PLUGIN_H
#define MAIN_PLUGIN_H

#include <Add_Plugin.hpp>
#include <string>
#include <vector>

using namespace std;

class Main_plugin
{
	public:
		Main_plugin();
		vector<Add_Plugin*> getPlugins();
	private:
		vector<Add_Plugin*> all_plugin;
		string path = "./plugins/";
};

#endif