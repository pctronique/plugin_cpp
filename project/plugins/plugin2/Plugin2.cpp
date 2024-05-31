#include <iostream>
#include <string>
#include <Plugin2.hpp>
#include <AddPluginInterface.hpp>

using namespace std;

string Plugin2::getName() {
    return "plugin2";
}

string Plugin2::getMessage(){
    return "the plugin2";
}


