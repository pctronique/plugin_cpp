#ifndef ADD_PLUGIN_H
#define ADD_PLUGIN_H

#include <string>

using namespace std;

class Add_Plugin
{
	public:
		virtual string getName();
		virtual string getMessage();
		virtual bool isPlugin();
};
 
typedef Add_Plugin *(*maker_Add_Plugin)();

#endif