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


class Colloseum {
private:
    std::vector<Character*> characterList;


public:
    Colloseum();
    void displayAllCharacters();
    ~Colloseum();
    void attack(Character*, Character*);
};

Colloseum::Colloseum() {
    
    characterList.push_back(new Ninja("Kawaki", 100));
    characterList.push_back(new Ninja("Naruto", 100));
    characterList.push_back(new Viking("Thorson", 100));

    attack(characterList[0], characterList[1]);
};

Colloseum::~Colloseum() {
    std::cout << "\nAll Characters in the Colloseum were deleted\n";
    for (int i = 0; i < characterList.size(); i++) {
        delete characterList[i];
    }
};

void Colloseum::displayAllCharacters() {
    std::cout << "The Colloseum Contains: " << std::endl;
    for (int i = 0; i < characterList.size(); i++) {
        characterList[i]->getCharacterInfo();
    }
}
void Colloseum::attack(Character* attacker, Character* receiver) {
   
    std::cout << attacker->getName() << " attacks " << receiver->getName() <<
        ".\n\tPrev health : " << receiver->getHealth() << "\t Damage done : " << attacker->getDamage();

    receiver->setHealth(attacker->getHealth() - receiver->getDamage());

     std::cout << "\t New Health : " << receiver->getHealth() << std::endl;
}


#endif
