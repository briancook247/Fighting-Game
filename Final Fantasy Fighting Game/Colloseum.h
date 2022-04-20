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


class Colloseum {
private:
    std::vector<Character*> characterList;
    std::vector<Character*> enemyList;
    Shop shop;
    
public:
    Colloseum();
    void displayAllCharacters();
    void displayAllEnemies();
    ~Colloseum();
    void attack(Character*, Character*);

    void start();
    void battle();
    void goToShop();

    void newCharacter();
};

#endif
