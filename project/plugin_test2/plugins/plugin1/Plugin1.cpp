#include <iostream>
#include <string>
#include <Plugin1.hpp>

using namespace std;

string Plugin1::getName() {
    return "plugin1";
}

string Plugin1::getMessage(){
    return "the plugin1";
}