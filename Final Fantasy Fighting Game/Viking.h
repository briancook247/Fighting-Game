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
    Viking() { setName(""); setMaxHealth(100); setHealth(100); };
    Viking(std::string n, double h) { setName(n); setMaxHealth(h); setHealth(h); };

    void getCharacterInfo() { std::cout << "Name: " << getName() << "\tHealth: (" << getHealth() << " / " << getMaxHealth() << ")\n"; };
    std::string getClass() { return "Viking"; }
};

#endif
