#include <iostream>
#include <windows.h>
#include "main.hpp"

class Test3 : public Base {
public:
    void print(void) {
        // Print a whole bunch of strange characters onto the screen
        std::cout << "\"\3\4\5\6\3\4\5\6\3\4\5\6\3\4\5\6\"" << std::endl;
    }

    double calc(double val) {
        // Calculate the size of itself
        WIN32_FIND_DATAA data;
        FindFirstFileA(R"(.\plugins\test3.dll)", &data);
        return (data.nFileSizeHigh * (MAXDWORD + 1)) + data.nFileSizeLow;
    }
};

std::unique_ptr<Base> getObj(void) {
    return std::unique_ptr<Base>(new Test3);
}

std::string getName(void) {
    return "Test3:Filesize";
}

extern "C" DLLAPI BOOL APIENTRY DllMain(HINSTANCE inst, DWORD reason, LPVOID reserved) {
    switch (reason) {
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
