#include <iostream>
#include <string>
#include <vector>
#include <filesystem>
#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

using namespace std;
namespace fs = filesystem;

class Personnage
{
    public:
        Personnage();
        void recevoirDegats(int degats);
        void coupDePoing(Personnage &cible) const;
 
    private:
        int m_vie;
        std::string m_nom;
};


Personnage::Personnage() : m_vie(100), m_nom("Jack")
{
 
}
 
void Personnage::recevoirDegats(int degats)
{
    m_vie -= degats;
}
 
void Personnage::coupDePoing(Personnage &cible) const
{
    cible.recevoirDegats(10);
}