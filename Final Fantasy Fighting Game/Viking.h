/*
* Brian Cook
* CST-210 (3pm)
* 4/3/2022
* My Own Work
*/
#ifndef VIKING_H
#define VIKING_H

#include "Character.h"

class Viking : public Character {

public:
    Viking() { setName(""); setMaxHealth(350); setHealth(350); setDamage(80); setDefense(0); setBalance(0); };
    Viking(std::string n, int h) { setName(n); setMaxHealth(h); setHealth(h); setDamage(78); setDefense(0); };

    void getCharacterInfo() { std::cout << " " << std::setw(13) << std::left << getName() << "\t(" << getHealth() << " / " << getMaxHealth() << ") Health\n"; };
    
   // void equipWeapon();
    
    std::string getClass() { return "Viking"; }

};

#endif
