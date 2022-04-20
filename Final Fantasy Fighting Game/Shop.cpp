#include "Shop.h"

Shop::Shop()
{
    
    shopInventory.push_back(new Sword("Katana", 48, 24, idCt++));
    shopInventory.push_back(new Bow("Longbow", 45, 22, idCt++));
    shopInventory.push_back(new Sword("Greatsword", 50, 25, idCt++));
}



void Shop::showAllItems()
{
    for (int i = 0; i < shopInventory.size(); i++) {
        shopInventory[i]->getItemInfo();
    }
}

Asset* Shop::buyItem()
{
    bool exitShop = false;
    std::string input;

    while (exitShop != true) {
        std::cout << "\nType the id# of an item to purchase... # ";
        std::cin >> input;
        int id = stoi(input);
        return shopInventory[0];
    }
}

Shop::~Shop(){
    for (int i = 0; i < shopInventory.size(); i++) {
         delete shopInventory[i];
    }
}
