#ifndef PLUGIN1_H
#define PLUGIN1_H

#include <AddPluginInterface.hpp>

using namespace std;

class Plugin3 : public AddPluginInterface {
	public:
		virtual string getName();
		virtual string getMessage();
};

extern "C"
{
    AddPluginInterface *make_AddPluginInterface()
    {
        return new Plugin3();
    }
}

#endif