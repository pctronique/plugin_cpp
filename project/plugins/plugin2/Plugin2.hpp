#ifndef PLUGIN1_H
#define PLUGIN1_H

#include <AddPluginInterface.hpp>

using namespace std;

class Plugin2 : public AddPluginInterface {
	public:
		virtual string getName();
		virtual string getMessage();
};

extern "C"
{
    AddPluginInterface *make_AddPluginInterface()
    {
        return new Plugin2();
    }
}

#endif