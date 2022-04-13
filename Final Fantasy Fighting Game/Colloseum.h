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
    //Character* characterList[2];
    //int numCharacters;
public:
    Colloseum();
    void displayAllCharacters();
    ~Colloseum();
};

Colloseum::Colloseum() {
    //numCharacters = 0;
    characterList.push_back(new Ninja("Kawaki", 100));
    characterList.push_back(new Ninja("Naruto", 100));
    characterList.push_back(new Viking("Thorson", 100));

    //characterList[numCharacters++] = new Ninja("Kawaki", 100);
    //characterList[numCharacters++] = new Viking("Askelad", 100);
   // characterList[numCharacters++] = new Ninja("Naruto", 100);
   // characterList[numCharacters++] = new Viking("Thorson", 100);
   // characterList[numCharacters++] = new Ninja("Sasuke", 100);
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
//void Colloseum::displayAllCharacters() {
//    std::cout << "The Colloseum Contains: " << std::endl;
//    for (Character *c : characterList) {
//        c->getCharacterInfo();
//    }
//}
#endif
