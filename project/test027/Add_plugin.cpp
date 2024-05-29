#include <iostream>
#include <string>
#include "Add_Plugin.hpp"

using namespace std;

string Add_Plugin::getName() {
    return "testplugin";
}

string Add_Plugin::getMessage(){
    return "";
}

bool Add_Plugin::isPlugin(){
    return true;
}

extern "C"
{
    Add_Plugin *make_Add_Plugin()
    {
        return new Add_Plugin();
    }
}
