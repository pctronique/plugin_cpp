#include "Add_Plugin.hpp"
#include <iostream>
#include <dlfcn.h>
 
using namespace std;
 
int main(int argc, char **argv)
{
    void *hndl;
    maker_Add_Plugin pMaker;
 
    // Ouverture de la librairie
    hndl = dlopen("./libcircle.so", RTLD_LAZY);
    if(hndl == NULL)
    {
        cerr << "dlopen : "<< dlerror() << endl; 
        exit(EXIT_FAILURE);
    }
 
    // Chargement du créateur
    void *mkr = dlsym(hndl, "make_add_plugin");
    if (mkr == NULL)
    {
        cerr << "dlsym : " << dlerror() << endl;
        exit(EXIT_FAILURE);
    }
    pMaker = (maker_Add_Plugin)mkr;
 
 
    // Création, affichagedu cercle
    Add_Plugin *my_circle = pMaker();
    my_circle->getName();
    dlclose(hndl);
 
    return EXIT_SUCCESS;
}