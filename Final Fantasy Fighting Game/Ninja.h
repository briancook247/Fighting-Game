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

public:
    Ninja() { setName(""); setMaxHealth(350); setHealth(350); setDamage(80); setDefense(0); setBalance(0); };
    Ninja(std::string n, int h) { setName(n); setMaxHealth(h); setHealth(h); setDamage(80); setDefense(0); setBalance(0); };
   
    
    void getCharacterInfo() { std::cout << " " << std::setw(13) << std::left << getName() << "\t(" << getHealth() << " / " << getMaxHealth() << ") Health\n"; };
    
   // void equipWeapon();
    
    std::string getClass() { return "Ninja"; }

};

#endif
