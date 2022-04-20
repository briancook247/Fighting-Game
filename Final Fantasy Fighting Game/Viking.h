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
private:

public:
    Viking() { setName(""); setMaxHealth(100); setHealth(100); setDamage(10); setDefense(0); };
    Viking(std::string n, int h) { setName(n); setMaxHealth(h); setHealth(h); setDamage(10); setDefense(0); };

    void getCharacterInfo() { std::cout << "\t" << getName() << "\tHealth: (" << getHealth() << " / " << getMaxHealth() << ")\n"; };
    
   // void equipWeapon();
    
    std::string getClass() { return "Viking"; }

};

#endif
