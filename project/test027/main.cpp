#include "Add_Plugin.hpp"
#include <iostream>
#include <dlfcn.h>
 
using namespace std;
 
int main(int argc, char **argv)
{
    void *hndl;
    
    typedef Add_Plugin *(*maker_Add_Plugin)();
    //maker_Add_Plugin pMaker;
 
    // Ouverture de la librairie
    hndl = dlopen("./libcircle1.so", RTLD_LAZY);
    if(hndl == NULL)
    {
        cerr << "dlopen : "<< dlerror() << endl; 
        exit(EXIT_FAILURE);
    }

    //typedef Add_Plugin *(*MyClass_c)();
 
    // Chargement du créateur
    maker_Add_Plugin mkr = (maker_Add_Plugin)dlsym(hndl, "make_Add_Plugin");
    if (mkr == NULL)
    {
        cerr << "dlsym : " << dlerror() << endl;
        exit(EXIT_FAILURE);
    }
    //pMaker = (maker_Add_Plugin)mkr;

    cout << "testing\n";

    // Création, affichagedu cercle
    Add_Plugin* my_circle = mkr();
    my_circle->getName();
    dlclose(hndl);
 
    return EXIT_SUCCESS;
}