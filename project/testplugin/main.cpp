#include <iostream>
#include <string>
#include <Main_plugin.hpp>

int main() {
    Main_plugin main_plugin;
    for (Add_Plugin* add_plugin : main_plugin.getPlugins()) {
        cout << add_plugin->getName() << " : " << add_plugin->getMessage() << "\n";
    }
    return 0;
}