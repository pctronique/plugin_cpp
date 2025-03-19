#include <iostream>
#include <string>
#include <Main_plugin.hpp>

int main() {
    Main_plugin main_plugin;
    main_plugin.loadPlugins();
    for (AddPluginInterface* addPluginInterface : main_plugin.getPlugins()) {
        cout << addPluginInterface->getName() << " : " << addPluginInterface->getMessage() << "\n";
    }
    return 0; 
}