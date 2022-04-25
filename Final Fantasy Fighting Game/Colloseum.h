/*
* Brian Cook
* CST-210 (3pm)
* 4/10/2022
* My Own Work
*/
#ifndef COLLOSEUM_H
#define COLLOSEUM_H
#include <string>
#include <vector>
#include <iostream>
#include "Character.h"
#include "Viking.h"
#include "Ninja.h"
#include "Shop.h"
#include <Windows.h>
#include <fstream>
#include <conio.h>
#include "Asset.h"
#include "Sword.h"
#include "HealthPotion.h"



class Colloseum {
private:
    std::vector<Character*> characterList;
    //Character* player;
    std::vector<Character*> enemyList;
    Shop shop;
    Sword* swordPtr;
    Bow* bowPtr;
    LightArmor* lArmorPtr;
    HeavyArmor* hArmorPtr;
    HealthPotion* healthPtr;
    
public:
    Colloseum();
    void displayAllCharacters();
    void displayAllEnemies();
    ~Colloseum();
    void attack(Character*, Character*);
    void start();
    void battle();
    void goToShop();
    void characterSelect();
    void loadCharacter(std::istream& in, std::vector <Character*> cList);
    void newCharacter();

    void printIntro();
};

#endif
