#include <iostream>
#include <string>
#include <Plugin1.hpp>

int main() {
    Plugin1 plugin1;
    cout << plugin1.getName() << "\n";
    if(plugin1.isPlugin()) {
        cout << "isplugin" << "\n";
    }
    return 0;
}