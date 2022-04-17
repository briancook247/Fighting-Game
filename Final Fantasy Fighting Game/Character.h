/*
* Brian Cook
* CST-210 (3pm)
* 4/3/2022
* My Own Work
*/
#ifndef CHARACTER_H
#define CHARACTER_H

//#include "Asset.h"
#include <iostream>
#include<vector>

class Character {
private:
    std::string name;
    int maxHealth;
    int health;
    int numAssets;
    int damage;
    int defense;
    //Asset* myAssets[2];
    //std::vector<Asset*> inventory;
public:
    void setName(std::string n) { this->name = n; }
    std::string getName() const { return name; }
    void setMaxHealth(int newMaxHealth) { this->maxHealth = newMaxHealth; }
    int getMaxHealth() const { return maxHealth; }
    void setHealth(int newHealth) { this->health = newHealth; }
    int getHealth() const { return health; };
    void setDamage(int newDamage) { this->damage = newDamage; }
    int getDamage() const { return damage; };
    void setDefense(int newDefense) { this->defense = newDefense; }
    int getDefense() const { return defense; };

    virtual void getCharacterInfo() = 0;
    virtual std::string getClass() = 0;

    /*friend std::ostream& operator<<(std::ostream& out, const Character& c) {
        out << c.name << "\tHealth: (" << c.health << " / " << c.maxHealth << ")\n\n";
        return out;
    };*/
};

//Character::~Character() {
//    for (int i = 0; i < numAssets; i++) {
//        delete myAssets[i];
//    }
//}

#endif
