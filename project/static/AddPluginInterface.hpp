#ifndef ADDPLUGININTERFACE_H
#define ADDPLUGININTERFACE_H

#include <string>

using namespace std;

class AddPluginInterface
{
	public:
		virtual string getName() = 0;
		virtual string getMessage() = 0;
};

/*
extern "C"
{
    AddPluginInterface *make_AddPluginInterface()
    {
        return new Name_Plugin();
    }
}
*/

#endif
