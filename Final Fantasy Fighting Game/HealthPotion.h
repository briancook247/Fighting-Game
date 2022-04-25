/*
* Brian Cook
* CST-210 (3pm)
* 4/3/2022
* My Own Work
*/
#ifndef HEALTHPOTION_H
#define HEALTHPOTION_H

#include "Asset.h"

class HealthPotion : public Asset {
private:
    int health;
    std::string name;
public:
    HealthPotion() {
        this->name = "Null Health Potion";
        this->health = 20;
        setPrice(2);
    };

    HealthPotion(int id, int tier) {
        if (tier == 1) {
            this->name = "Health I Potion";
            this->health = 50;
            setPrice(25);
            setId(id);
        }
        else if (tier == 2) {
            this->name = "Health II Potion";
            this->health = 100;
            setPrice(50);
            setId(id);
        }
        else if (tier == 3) {
            this->name = "Health III Potion";
            this->health = 200;
            setPrice(85);
            setId(id);
        }
    };
    void setName(std::string n) { this->name = n; }
    std::string getName() const { return name; }
    void setHealth(int health) { this->health = health; }
    int getHealth() const { return health; }
    void getItemInfo() { std::cout << "\t" << std::setw(20) << std::left << getName() << "\t\tHealth: " << getHealth() << "\t\tPrice: " << getPrice() << "$\n"; };

};

#endif
