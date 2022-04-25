/*
* Brian Cook
* CST-210 (3pm)
* 4/3/2022
* My Own Work
*/
#ifndef HEAVYARMOR_H
#define HEAVYARMOR_H

#include "Asset.h"

class HeavyArmor : public Asset {
private:
    std::string name;
    int defense;
public:
    HeavyArmor() {
        this->name = "Heavy Armor";
        this->defense = 30;
    };
    HeavyArmor(std::string name, int defense, int price, int id) {
        this->name = name;
        this->defense = defense;
        setPrice(price);
        setId(id);
    };
    void setName(std::string n) { this->name = n; }
    std::string getName() const { return name; }
    void setDefense(int defense) { this->defense = defense; }
    int getDefense() const { return defense; }
    void getItemInfo() { std::cout << "\t" << std::setw(20) << std::left << getName() << "\t\tDefense: " << getDefense() << "\t\tPrice: " << getPrice() << "$\n"; };
};

#endif
