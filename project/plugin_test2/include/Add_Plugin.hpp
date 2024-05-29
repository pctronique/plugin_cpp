#ifndef ADD_PLUGIN_H
#define ADD_PLUGIN_H

#include <string>

using namespace std;

class Add_Plugin
{
	public:
		string getName(){ return ""; };
		string getMessage(){ return ""; };
		bool isPlugin(){ return true; };
};

#endif