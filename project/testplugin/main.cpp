#include <iostream>
#include <string>
#include <Main_plugin.hpp>

int main() {
    Main_plugin main_plugin;
    main_plugin.loadPlugins();
    for (AddPluginInterface* AddPluginInterface : main_plugin.getPlugins()) {
        cout << AddPluginInterface->getName() << " : " << AddPluginInterface->getMessage() << "\n";
    }
    return 0; 
}