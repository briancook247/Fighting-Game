#include "Colloseum.h"

Colloseum::Colloseum() {

    enemyList.push_back(new Ninja("Madara", 150));
    enemyList.push_back(new Viking("Askelad", 130));
    enemyList.push_back(new Ninja("Tobi", 130));

};

Colloseum::~Colloseum() {
    std::cout << "\nAll Characters and Enemies in the Colloseum were deleted\n";
    for (int i = 0; i < characterList.size(); i++) {
        delete characterList[i];
    }
    for (int i = 0; i < enemyList.size(); i++) {
        delete enemyList[i];
    }
};

void Colloseum::displayAllCharacters() {

    for (int i = 0; i < characterList.size(); i++) {
        characterList[i]->getCharacterInfo();
    }
}

void Colloseum::displayAllEnemies() {

    for (int i = 0; i < enemyList.size(); i++) {
        enemyList[i]->getCharacterInfo();
    }
}

void Colloseum::attack(Character* attacker, Character* receiver) {

    std::cout << attacker->getName() << " attacks " << receiver->getName() <<
        ".\n\tPrev health : " << receiver->getHealth() << "\t Damage done : " << attacker->getDamage();

    receiver->setHealth(receiver->getHealth() - attacker->getDamage());
    if (receiver->getHealth() > 0) {
        std::cout << "\t New Health : " << receiver->getHealth() << std::endl;
    }
    // fix later, we get money if our character dies rn, make another case for when our character dies to lose battle
    //else if (attacker != characterList[0]) {
    else {
        std::cout << "\t" << receiver->getName() << " was killed.\n";
        srand(time(NULL));
        int randCoins = rand() % 30;
        attacker->setBalance(attacker->getBalance() + 20 + randCoins);
        std::cout << "\t\t* You earned " << 20 + randCoins <<" coins from killing " << receiver->getName()  << " * " << "\n\n";
    }
}

void Colloseum::goToShop()
{
  
    std::cout << "\n";
    shop.showAllItems();
    std::cout << "\nYour Balance: " << characterList[0]->getBalance() << "$\n";

    characterList[0]->addToInv(shop.buyItem());
    characterList[0]->showInv();
}

void Colloseum::start()
{
    
    std::cout << "\nWelcome to The...\n"; Sleep(800);
    printIntro(); Sleep(700);

    characterSelect();

    std::cout<<"\n\tYour team has... \n------------------------------- \n"; displayAllCharacters();
    std::cout << "\n-------------------------------\n\n\tYou will be fighting...\n-------------------------------\n"; displayAllEnemies();

    std::string input;
    bool exit = false;
    while (exit != true) {
        std::cout << "\nBefore the battle begins, would you like to visit the shop? (Q to visit shop, E to begin battle)\n";
        std::cin >> input;
        if (input == "q" || input == "Q") {
            goToShop();
        }
        else if (input == "e" || input == "E") {
            battle();
        }
        
    }
}

void Colloseum::battle() {

    std::string input;
    bool endBattle = false;
    int randNum;
    while (endBattle != true) {
         
       
        std::cout << "\n\nThe Battle Begins...\n";
        while (endBattle != true) {
            std::cout << "Press [1] to attack\t [2] to check inventory\t [3] to switch characters\t [4] to leave battle\n";
            std::cin >> input;
            if (input == "1") {
                std::cout << "Select an enemy to attack : \n\n1: " << enemyList[0]->getName() << "\n2 : " << enemyList[1]->getName() << "\n3 : " << enemyList[2]->getName() << "\n\n";
            }
            else if (input == "2") {
                characterList[0]->showInv();
            }
            else if (input == "3") {
                //switchCharacters();
            }
            else if (input == "4") {
                endBattle = true;
            }
        }
     
        std::cin >> input;
        // Random Number 1-5 for per move for odds of deflection
        srand(time(NULL));
        randNum = rand() % 3 + 1;

        if (input == "1" && enemyList[0]->getHealth() > 0) {
            if (randNum != 3) {
                attack(characterList[0], enemyList[0]);
            }
            else {
                std::cout << "The attack has been deflected, ";
                attack(enemyList[0], characterList[0]);
            }
        }
        else if (input == "2" && enemyList[1]->getHealth() > 0) {
            if (randNum != 3) {
                attack(characterList[0], enemyList[1]);
            }
            else {
                std::cout << "The attack has been deflected, ";
                attack(enemyList[1], characterList[0]);
            }
        }
        else if (input == "3" && enemyList[2]->getHealth() > 0) {
            if (randNum != 3) {
                attack(characterList[0], enemyList[2]);
            }
            else {
                std::cout << "The attack has been deflected, ";
                attack(enemyList[2], characterList[0]);
            }
        }
        else {
            std::cout << "\nThat enemy is either dead or does not exist, try again...\n\n";
        }

        endBattle = true;
    }
}

void Colloseum::characterSelect() {
    std::string input;
    std::cout << "\n\nWould you like to load a previous character save (press [Q]) or make a new character (press [E])?\n";
    while (std::cin >> input) {
        if (input == "q" || input == "Q") {
            std::cout << "What was the name of your character?" << "\n";
            std::cin >> input;
            // use getline instead
            loadCharacter(input);
            break;
        }
        else if (input == "e" || input == "E") {
            newCharacter();
            break;
        }
    }
}

void Colloseum::loadCharacter(std::string charName) {

}

void Colloseum::newCharacter()
{
    std::cout << "Choose a class: Ninja or Viking... \n";
    std::string input;
    while (std::cin >> input) {
        if (input == "ninja" || input == "Ninja") {

            std::cout << "Choose a name for your ninja: ";
            std::cin >> input;
            characterList.push_back(new Ninja(input, 100));
            break;
        }
        else if (input == "viking" || input == "Viking") {

            std::cout << "Choose a name for your viking: ";
            std::cin >> input;
            characterList.push_back(new Viking(input, 100));
            break;
        }
    }
}

void Colloseum::printIntro() {
    std::string p1 = " ________  ________  ___       ___       ________  ________  _______   ___  ___  _____ ______      ";
    std::string p2 = "|\\   ____\\|\\   __  \\|\\  \\     |\\  \\     |\\   __  \\|\\   ____\\|\\  ___ \\ |\\  \\|\\  \\|\\   _ \\  _   \\    ";
    std::string p3 = "\\ \\  \\___|\\ \\  \\|\\  \\ \\  \\    \\ \\  \\    \\ \\  \\|\\  \\ \\  \\___|\\ \\   __/|\\ \\  \\\\\\  \\ \\  \\\\\\__\\ \\  \\   ";
    std::string p4 = " \\ \\  \\    \\ \\  \\\\\\  \\ \\  \\    \\ \\  \\    \\ \\  \\\\\\  \\ \\_____  \\ \\  \\_|/_\\ \\  \\\\\\  \\ \\  \\|__|\\ \\  \\  ";
    std::string p5 = "  \\ \\  \\____\\ \\  \\\\\\  \\ \\  \\____\\ \\  \\____\\ \\  \\\\\\  \\|____|\\  \\ \\  \\_|\\ \\ \\  \\\\\\  \\ \\  \\    \\ \\  \\ ";
    std::string p6 = "   \\ \\_______\\ \\_______\\ \\_______\\ \\_______\\ \\_______\\____\\_\\  \\ \\_______\\ \\_______\\ \\__\\    \\ \\__\\";
    std::string p7 = "    \\|_______|\\|_______|\\|_______|\\|_______|\\|_______|\\_________\\|_______|\\|_______|\\|__|     \\|__|";

    std::cout << p1 << std::endl;
    std::cout << p2 << std::endl;
    std::cout << p3 << std::endl;
    std::cout << p4 << std::endl;
    std::cout << p5 << std::endl;
    std::cout << p6 << std::endl;
    std::cout << p7 << std::endl;

}


