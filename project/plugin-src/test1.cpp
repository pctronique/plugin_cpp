#include <iostream>
#include <cmath>
#include <windows.h>
#include "main.hpp"

class Test1 : public Base {
public:
    void print(void) {
        std::cout << "Hello Everybody! Test1!" << std::endl;
    }

    double calc(double val) {
        return sqrt(abs(val/5*1.61));
    }
};

std::unique_ptr<Base> getObj(void) {
    return std::unique_ptr<Base>(new Test1);
}

std::string getName(void) {
    return "Test1:Maths";
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
