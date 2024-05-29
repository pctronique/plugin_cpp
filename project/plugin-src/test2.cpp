#include <iostream>
#include <random>
#include <ctime>
#include <windows.h>
#include "main.hpp"

class Test2 : public Base {
public:
    void print(void) {
        std::cout << "This is Test2 Speaking!" << std::endl;
    }

    double calc(double val) {
        return val * this->_dist(this->_randGen);
    }

private:
    std::mt19937 _randGen {static_cast<unsigned>(time(nullptr))};
    std::uniform_real_distribution<double> _dist {0.0, 100.0};
};

std::string getName(void) {
    return "Test2:RandNum";
}

std::unique_ptr<Base> getObj(void) {
    return std::unique_ptr<Base>(new Test2);
}

extern "C" DLLAPI BOOL APIENTRY DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
    switch (fdwReason)
    {
        case DLL_PROCESS_ATTACH:
            // attach to process
            // return FALSE to fail DLL load
            break;

        case DLL_PROCESS_DETACH:
            // detach from process
            break;

        case DLL_THREAD_ATTACH:
            // attach to thread
            break;

        case DLL_THREAD_DETACH:
            // detach from thread
            break;
    }
    return TRUE; // succesful
}
