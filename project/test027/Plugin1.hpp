#ifndef PLUGIN1_H
#define PLUGIN1_H

#include "Add_Plugin.hpp"

using namespace std;

class Plugin1 : public Add_Plugin {
	public:
		string getName();
		string getMessage();
};

#endif