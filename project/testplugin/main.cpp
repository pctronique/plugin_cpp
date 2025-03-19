#include <iostream>
#include <string>
#include <PctrPlugin.hpp>
#include <AddPluginInterface.hpp>

int main() {
    PctrPlugin main_plugin = PctrPlugin("AddPluginInterface");
    main_plugin.loadPlugins();
    for (void* addPluginInterface : main_plugin.getPlugins()) {

        cout << ((AddPluginInterface*)addPluginInterface)->getName() << " : " << ((AddPluginInterface*)addPluginInterface)->getMessage() << "\n";
    }
    return 0; 
}