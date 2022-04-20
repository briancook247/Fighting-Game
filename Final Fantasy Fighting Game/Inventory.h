/*
* Brian Cook
* CST-210 (3pm)
* 4/10/2022
* My Own Work
*/
#ifndef INVENTORY_H
#define INVENTORY_H
#include "Asset.h"
#include "Sword.h"
#include "Bow.h"

class Inventory {
private:
    std::vector<Asset*> inventory;
    int invCt = 1;
public:
    Inventory() {
        inventory.push_back(new Sword("Trusty Sword", 40, 20, invCt++));
    }
    void showInventory() {
        for (int i = 0; i < inventory.size(); i++) {
            inventory[i]->getItemInfo();
        }
    }
    void addItem(Asset* item) {
        inventory.push_back(item);
    }

    //void equipItem();
    ~Inventory() {
        for (int i = 0; i < inventory.size(); i++) {
            delete inventory[i];
        }
    }
};

#endif
