#include <iostream>
#include <string>
#include <Plugin1.hpp>
#include <Add_Plugin.hpp>

using namespace std;

string Plugin1::getName() {
    return "plugin1";
}

string Plugin1::getMessage(){
    return "the plugin1";
}

extern "C"
{
    Add_Plugin *make_add_plugin()
    {
        return new Plugin1();
    }
}
