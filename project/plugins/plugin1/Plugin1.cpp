#include <iostream>
#include <string>
#include <Plugin1.hpp>
#include <AddPluginInterface.hpp>

using namespace std;

string Plugin1::getName() {
    return "plugin1";
}

string Plugin1::getMessage(){
    return "the plugin1";
}

extern "C"
{
    AddPluginInterface *make_AddPluginInterface()
    {
        return new Plugin1();
    }
}
