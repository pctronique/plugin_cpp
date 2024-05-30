#ifndef ADD_PLUGIN_H
#define ADD_PLUGIN_H

#include <string>

using namespace std;

class Add_Plugin
{
	public:
		virtual string getName() { return "tintin021"; };
		virtual string getMessage(){ return ""; };
		virtual bool isPlugin(){ return true; };
};

#endif