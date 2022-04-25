#include "Shop.h"

Shop::Shop()
{
    shopInventory.push_back(new Sword("Katana", 48, 24, idCt++));
    shopInventory.push_back(new Bow("Longbow", 45, 22, idCt++));
    shopInventory.push_back(new Sword("Greatsword", 50, 25, idCt++));
    shopInventory.push_back(new LightArmor("Ninja Suit", 30, 25, idCt++));
    shopInventory.push_back(new HeavyArmor("Viking Armor", 35, 30, idCt++));
    shopInventory.push_back(new HealthPotion(idCt++, 1));
    shopInventory.push_back(new HealthPotion(idCt++, 2));
    shopInventory.push_back(new HealthPotion(idCt++, 3));
}

int Shop::getSize() {
    return shopInventory.size();
}

void Shop::showAllItems()
{
    std::cout << "\n---------------------------------S H O P---------------------------------\n";
    std::cout << "\n-------------------------------------------------------------------------\n";
    for (int i = 0; i < shopInventory.size(); i++) {
        std::cout << shopInventory[i]->getId();
        shopInventory[i]->getItemInfo();
    }

}

Asset* Shop::buyItem(int id)
{
    return shopInventory[id - 1];
}

Shop::~Shop(){
    for (int i = 0; i < shopInventory.size(); i++) {
         delete shopInventory[i];
    }
}
