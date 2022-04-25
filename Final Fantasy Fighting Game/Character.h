/*
* Brian Cook
* CST-210 (3pm)
* 4/3/2022
* My Own Work
*/
#ifndef CHARACTER_H
#define CHARACTER_H


#include <iostream>
#include<vector>
#include "Inventory.h"
#include <string>


class Character {
private:
    std::string name;
    int maxHealth;
    int health;
    int numAssets;
    int damage;
    int defense;
    Inventory inventory;
    Asset* curWeapon;
    int balance;
public:
    void setName(std::string n) { this->name = n; }
    std::string getName() const { return name; }
    void setMaxHealth(int newMaxHealth) { this->maxHealth = newMaxHealth; }
    int getMaxHealth() const { return maxHealth; }
    void setHealth(int newHealth) { this->health = newHealth; }
    int getHealth() const { return health; }
    void setDamage(int newDamage) { this->damage = newDamage; }
    int getDamage() const { return damage; }
    void setDefense(int newDefense) { this->defense = newDefense; }
    int getDefense() const { return defense; }
    void setBalance(int newBalance) { this->balance = newBalance;  }
    int getBalance() const { return balance; }

    void addToInv(Asset* item) {
        inventory.addItem(item);
        
    }

    Asset* getCurrentWeapon() {
        return curWeapon;
    }

    void setCurrentWeapon(int id) {
        curWeapon = inventory.equipItem(--id);
    }

    void showInv() {
        std::cout << "\n----------------------------I N V E N T O R Y----------------------------\n\n";
        inventory.showInventory();
        std::cout << "\n-------------------------------------------------------------------------\n";
    }

    virtual void getCharacterInfo() = 0;
   // virtual void inventory() = 0;
    virtual std::string getClass() = 0;
   // virtual void equip(int) = 0;

   /* friend std::ostream& operator<<(std::ostream& out, const Character* c) {
        out << c->getName() << "\tHealth: (" << c->getHealth() << " / " << c->getMaxHealth() << ")\n\n";
        return out;
    }

    friend std::istream& operator>>(std::istream& in, Character* c) {
        in >> c->name;
        in >> c->damage;
        getline(in, c.phone);
        c.setId(Contact::totalCt);
        return in;
    }*/
};

//Character::~Character() {
//    for (int i = 0; i < numAssets; i++) {
//        delete myAssets[i];
//    }
//}

#endif
