#ifndef __MAIN_HPP_INCLUDED__
#define __MAIN_HPP_INCLUDED__

#include <memory>
#include <string>

// Test to see if we are building a DLL.
// If we are, specify that we are exporting
// to the DLL, otherwise don't worry (we
// will manually import the functions).
#ifdef BUILD_DLL
    #define DLLAPI __declspec(dllexport)
#else
    #define DLLAPI
#endif // BUILD_DLL

// This is the base class for the class
// retrieved from the DLL. This is used simply
// so that I can show how various types should
// be retrieved from a DLL. This class is to
// show how derived classes can be taken from
// a DLL.
class Base {
public:
    virtual ~Base() = default;

    // Pure virtual print function, effect specific to DLL
    virtual void print(void) = 0;

    // Pure virtual function to calculate something, 
    //according to an unknown set of rules.
    virtual double calc(double val) = 0;
};


// DLL export funcs

// Get an instance of the derived class
// contained in the DLL.
DLLAPI std::unique_ptr<Base> getObj(void);

// Get the name of the plugin. This can
// be used in various associated messages.
DLLAPI std::string getName(void);

#endif // __MAIN_HPP_INCLUDED__
