// Program to demonstrate the use of a plugin system.

#include "main.hpp"
#include <iostream>
#include <vector>
#include <memory>
#include <stdexcept>
#include <exception>
#include <windows.h>

// Load the objects from the plugin folder.
//
// Takes as a parameter a reference to a list of modules,
// which will be emptied and then refilled with handles to
// the modules loaded. These should be freed with the
// FreeLibrary() after use.
//
// Returns a list of Base*, contained in a smart pointer
// to ease memory deallocation and help prevent memory
// leaks.
std::vector<std::unique_ptr<Base>> getPlugins(std::vector<HINSTANCE>& modules) {
    // A temporary structure to return.
    std::vector<std::unique_ptr<Base>> ret;
    // empty the modules list passed
    modules.clear();

    // Find the files contained in the 'plugins' folder
    WIN32_FIND_DATA fileData;
    HANDLE fileHandle = FindFirstFile(R"(.\plugins\*.dll)", &fileData);

    if (fileHandle == (void*)ERROR_INVALID_HANDLE ||
        fileHandle == (void*)ERROR_FILE_NOT_FOUND) {
        // If we couldn't find any plugins, quit gracefully,
        // returning an empty structure.
        return std::vector<std::unique_ptr<Base>>();
    }

    // Loop over every plugin in the folder and store in our
    // temporary return list
    do {
        // Define the function types for what we are retrieving
        typedef std::unique_ptr<Base> (__cdecl *ObjProc)(void);
        typedef std::string (__cdecl *NameProc)(void);

        // Load the library
        HINSTANCE mod = LoadLibrary((R"(.\plugins\)" + std::string(fileData.cFileName)).c_str());

        if (!mod) {
            // Couldn't load the library, cleaning module list and quitting.
            for (HINSTANCE hInst : modules)
                FreeLibrary(hInst);
            throw std::runtime_error("Library " + std::string(fileData.cFileName) + " wasn't loaded successfully!");
        }

        // Get the function and the class exported by the DLL.
        // If you aren't using the MinGW compiler, you may need to adjust
        // this to cope with name mangling (I haven't gone into this here,
        // look it up if you want).
        ObjProc objFunc = (ObjProc) GetProcAddress(mod, "_Z6getObjv");
        NameProc nameFunc = (NameProc) GetProcAddress(mod, "_Z7getNamev");


        if (!objFunc || !nameFunc)
            throw std::runtime_error("Invalid Plugin DLL: both 'getObj' and 'getName' must be defined.");

        // push the objects and modules into our vectors
        ret.push_back(objFunc());
        modules.push_back(mod);

        std::clog << nameFunc() << " loaded!\n";
    } while (FindNextFile(fileHandle, &fileData));

    std::clog << std::endl;

    // Close the file when we are done
    FindClose(fileHandle);
    return ret;
}

int main() {
    // Our list of modules. We need this to properly free the module
    // after the program has finished.
    std::vector<HINSTANCE> modules;

    // Enter a block, to prevent the Base objects being
    // deallocated after the modules are freed (which will
    // cause your program to crash)
    {
        // The list of objectects that we will retrieve from the DLL's.
        std::vector<std::unique_ptr<Base>> objs;

        // Load the plugins using our function
        try {
            objs = getPlugins(modules);
        } catch (const std::exception& e) {
            std::cerr << "Exception caught: " << e.what() << std::endl;
            return 1;
        }

        // Call the 'print' function for out classes.
        // This is normally where you would implement
        // the code for using the plugins.
        for (auto& x : objs) {
            x->print();
            std::cout << "\t" << x->calc(10) << std::endl;
        }
    }

    // Program finishing, time to clean up
    for (HINSTANCE hInst : modules)
        FreeLibrary(hInst);

    return 0;
}
