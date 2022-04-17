/*
* Brian Cook
* CST-210 (3pm)
* 4/3/2022
* My Own Work
*/
#ifndef NINJA_H
#define NINJA_H

#include "Character.h"

class Ninja : public Character {
private:
    
public:
    Ninja() { setName(""); setMaxHealth(100); setHealth(100); setDamage(10); setDefense(0); };
    Ninja(std::string n, int h) { setName(n); setMaxHealth(h); setHealth(h); setDamage(10); setDefense(0); };
   
    void getCharacterInfo() { std::cout << "Name: " << getName() << "\tHealth: (" << getHealth() << " / " << getMaxHealth() << ")\n"; };
    std::string getClass() { return "Ninja"; }

};

#endif
