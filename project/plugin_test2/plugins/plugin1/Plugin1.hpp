#ifndef PLUGIN1_H
#define PLUGIN1_H

//#include <Add_Plugin.hpp>
#include <string>
#include <vector>

using namespace std;

class Plugin1 : public Add_Plugin
{
	public:
		string getName(){ return ""; };
		string getMessage(){ return ""; };
		bool isPlugin(){ return true; };
};

#endif