/*
* Brian Cook
* CST-210 (3pm)
* 4/10/2022
* My Own Work
*/
#ifndef SHOP_H
#define SHOP_H
#include <string>
#include <vector>
#include <iostream>
#include "Sword.h"
#include "Bow.h"
#include "LightArmor.h"
#include "HeavyArmor.h"
#include "HealthPotion.h"


class Shop {
private:
    std::vector<Asset*> shopInventory;
    int idCt = 1;
public:
    Shop();
    void showAllItems();
    Asset* buyItem(int);
    int getSize();
    ~Shop();
};

#endif
