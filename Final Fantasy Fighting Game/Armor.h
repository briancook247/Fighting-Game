/*
* Brian Cook
* CST-210 (3pm)
* 4/3/2022
* My Own Work
*/
#ifndef ARMOR_H
#define ARMOR_H

#include "Asset.h"

class Armor : public Asset {
private:
    std::string name;
    int damage;
public:

    void setName(std::string n) { this->name = n; }
    std::string getName() const { return name; }
    void setDamage(int damage) { this->damage = damage; }
    int getDamage() const { return damage; }
};

#endif
