#ifndef ADD_PLUGIN_H
#define ADD_PLUGIN_H

#include <string>

using namespace std;

class Add_Plugin
{
	public:
		virtual string getName() = 0;
		virtual string getMessage() = 0;
};

/*
extern "C"
{
    Add_Plugin *make_add_plugin()
    {
        return new Name_Plugin();
    }
}
*/

#endif
