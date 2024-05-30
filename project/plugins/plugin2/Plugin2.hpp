#ifndef PLUGIN1_H
#define PLUGIN1_H

#include <Add_Plugin.hpp>

using namespace std;

class Plugin2 : public Add_Plugin {
	public:
		virtual string getName();
		virtual string getMessage();
};

extern "C"
{
    Add_Plugin *make_add_plugin()
    {
        return new Plugin2();
    }
}

#endif