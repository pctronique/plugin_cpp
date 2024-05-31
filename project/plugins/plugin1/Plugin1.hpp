#ifndef PLUGIN1_H
#define PLUGIN1_H

#include <AddPluginInterface.hpp>

using namespace std;

class Plugin1 : public AddPluginInterface {
	public:
		virtual string getName();
		virtual string getMessage();
};

#endif