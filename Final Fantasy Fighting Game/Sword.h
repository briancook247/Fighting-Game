/*
* Brian Cook
* CST-210 (3pm)
* 4/3/2022
* My Own Work
*/
#ifndef SWORD_H
#define SWORD_H

#include "Asset.h"

class Sword : public Asset {
private:
    std::string name;
    int damage;
public:
    Sword();
    Sword(std::string, int, int, int);
    void setName(std::string n) { this->name = n; }
    std::string getName() const { return name; }
    void setDamage(int damage) { this->damage = damage; }
    int getDamage() const { return damage; }
    void getItemInfo() { std::cout << "\t" << std::setw(20) << std::left << getName() 
        << "\t\tDamage: " << getDamage() << "\t\tPrice: " << getPrice() << "$\n"; };
};

#endif
