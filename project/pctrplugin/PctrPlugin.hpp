#ifndef PCTRPLUGIN_H
#define PCTRPLUGIN_H

#include <string>
#include <vector>

using namespace std;

class PctrPlugin
{
	public:
		PctrPlugin(string nameInterf);
		PctrPlugin loadPlugins(string folder = "");
		void closeLoad();
		vector<void*> getPlugins();
	private:
		vector<void*> all_plugin;
		string path = "./plugins/";
		string nameInterfLd = "";
};

#endif