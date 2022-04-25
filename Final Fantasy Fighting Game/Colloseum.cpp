#include "Colloseum.h"

Colloseum::Colloseum() {

	enemyList.push_back(new Ninja("Madara", 360));
	enemyList.push_back(new Viking("Askelad", 300));
	enemyList.push_back(new Ninja("Tobi", 290));

}

Colloseum::~Colloseum() {
	std::cout << "\nAll Characters and Enemies in the Colloseum were deleted\n";
	for (int i = 0; i < characterList.size(); i++) {
		delete characterList[i];
	}
	for (int i = 0; i < enemyList.size(); i++) {
		delete enemyList[i];
	}
}

void Colloseum::start()
{
	std::cout << "\nWelcome to The...\n"; Sleep(800);
	printIntro(); Sleep(700);

	characterSelect();

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

void Colloseum::displayAllCharacters() {

	std::cout << "\n\tYour team has... \n----------------------------------\n";
	for (int i = 0; i < characterList.size(); i++) {
		if (characterList[i]->getHealth() > 0) {
			characterList[i]->getCharacterInfo();
		}
		else {
			std::cout << " " << std::setw(13) << std::left << characterList[i]->getName() << "\tis Dead\n";
		}

		//std::cout << "Currently Holding: " << characterList[i]->getCurrentWeapon()->getName();
	}
	std::cout << "\n----------------------------------\n"; 
}

void Colloseum::displayAllEnemies() {
	std::cout << "\n\n\n\tEnemies Alive...\n----------------------------------\n";

	for (int i = 0; i < enemyList.size(); i++) {
		if (enemyList[i]->getHealth() > 0) {
			enemyList[i]->getCharacterInfo();
		}
		else {
			std::cout << " " <<std::setw(13) << std::left << enemyList[i]->getName() << "\tis Dead\n";
		}
	}
	std::cout << "\n----------------------------------\n";
}

void Colloseum::battle() {

	std::string input;
	bool endBattle = false;
	int enemiesDefeated;
	int randNum;

	std::cout << "\n\nThe Battle Begins...\n";
	while (endBattle != true) {
		enemiesDefeated = 0;
		displayAllCharacters();
		displayAllEnemies();
		std::cout << "\n [1] to attack\t\t [2] to check inventory\t\t [3] to leave battle\n";
		std::cin >> input;
		if (input == "1") {
			std::cout << "Select an enemy to attack : \n\n1: "
				<< enemyList[0]->getName() << 
				"\n2 : " << enemyList[1]->getName() << 
				"\n3 : " << enemyList[2]->getName() << "\n\n";

			std::cin >> input;
			// Random Number 1-5 for per move for odds of deflection
			srand(time(NULL));
			randNum = rand() % 3 + 1;
			system("cls");

			if (input == "1" ) {
				if (enemyList[0]->getHealth() > 0) {
					if (randNum != 3) {
						std::cout << "\n\n\n";
						attack(characterList[0], enemyList[0]);
					}
					else {
						std::cout << "\n\n\n\t\t\tThe attack has been deflected, ";
						attack(enemyList[0], characterList[0]);
					}
				}
				else {
					std::cout << "\n\n\n\t\t\tThat enemy has been defeated, pick a new enemy to attack";
				}
			}
			else if (input == "2") {
				if (enemyList[1]->getHealth() > 0) {
					if (randNum != 3) {
						std::cout << "\n\n\n";
						attack(characterList[0], enemyList[1]);
					}
					else {
						std::cout << "\n\n\n\t\t\tThe attack has been deflected, ";
						attack(enemyList[1], characterList[0]);
					}
				}
				else {
					std::cout << "\n\n\n\t\t\tThat enemy has been defeated, pick a new enemy to attack";
				}
				
			}
			else if (input == "3") {
				if (enemyList[2]->getHealth() > 0) {
					if (randNum != 3) {
						std::cout << "\n\n\n";
						attack(characterList[0], enemyList[2]);
					}
					else {
						std::cout << "\n\n\n\t\t\tThe attack has been deflected, ";
						attack(enemyList[2], characterList[0]);
					}
				}
				else {
					std::cout << "\n\n\n\t\t\tThat enemy has been defeated, pick a new enemy to attack";
				}
			}
			else {
				std::cout << "\nThat enemy is either dead or does not exist, try again...\n\n";
			}
		}

		else if (input == "2") {
			std::cout << "\n\n\n\n\n\n\n\n\n\n\n";
			characterList[0]->showInv();

		
			std::cout << "\nType an Item to equip/swap: #";
			std::cin >> input;
			int itemId = stoi(input);
			
			swordPtr = dynamic_cast<Sword*>(characterList[0]->getInvSlot(itemId));
			bowPtr = dynamic_cast<Bow*>(characterList[0]->getInvSlot(itemId));
			lArmorPtr = dynamic_cast<LightArmor*>(characterList[0]->getInvSlot(itemId));
			hArmorPtr = dynamic_cast<HeavyArmor*>(characterList[0]->getInvSlot(itemId));
			healthPtr = dynamic_cast<HealthPotion*>(characterList[0]->getInvSlot(itemId));\

			if (swordPtr != nullptr || bowPtr != nullptr)
			{
				characterList[0]->setCurrentWeapon(itemId);
				if (swordPtr != nullptr) {
					characterList[0]->setDamage(characterList[0]->getDamage() + swordPtr->getDamage());
				}
				else if (bowPtr != nullptr) {
					characterList[0]->setDamage(characterList[0]->getDamage() + bowPtr->getDamage());
				}
				std::cout << "\nCurrent Weapon Is:\n";
				characterList[0]->getCurrentWeapon()->getItemInfo();
			}
			else if (lArmorPtr != nullptr || hArmorPtr != nullptr) {
				characterList[0]->setCurrentArmor(itemId);
				if (lArmorPtr != nullptr) {
					characterList[0]->setMaxHealth(characterList[0]->getHealth() + lArmorPtr->getDefense());
				}
				else if (hArmorPtr != nullptr) {
					characterList[0]->setMaxHealth(characterList[0]->getHealth() + hArmorPtr->getDefense());
				}
			}
			else if (healthPtr != nullptr) {
				characterList[0]->setHealth(characterList[0]->getHealth() + healthPtr->getHealth());
			}

		}
		else if (input == "3") {
			endBattle = true;
			std::cout << "\n\nYou retreat... the battle has ended\n\n";
		}
		for (int i = 0; i < enemyList.size(); i++) {
			if (enemyList[i]->getHealth() <= 0) {
				enemiesDefeated++;
			}
		}
		if (enemiesDefeated == enemyList.size()) {
			endBattle = true;
			std::cout << "\n\n\n\n\n\n\n\n\n\n\n\t\tAll enemies were defeated... YOU HAVE WON THE BATTLE!\n";
		}
		std::cout << "\n\n\n" << "Enemies Defeated : " << enemiesDefeated << "\n\n\n";
	}
	//Save Character? q/e
}

void Colloseum::attack(Character* attacker, Character* receiver) {

	receiver->setHealth(receiver->getHealth() - attacker->getDamage());

	if (receiver->getHealth() > 0) {
	std::cout << "\n\t\t\t" << attacker->getName() << " does "  << attacker->getDamage() << " damage to " << receiver->getName() <<
		"!\tNew Health : (" << receiver->getHealth() << " / " << receiver->getMaxHealth() << ")";
	}
	else {
		std::cout << "\t" << receiver->getName() << " was killed.\n";
		srand(time(NULL));
		int randCoins = rand() % 30;
		attacker->setBalance(attacker->getBalance() + 20 + randCoins);
		std::cout << "\t\t* You earned " << 20 + randCoins << " coins from killing " << receiver->getName() << " * " << "\n\n";
	}
}
// Walks through shopping loop
void Colloseum::goToShop()
{
	bool stopShop = false;
	std::string input;
	characterList[0]->setBalance(200);

	while (stopShop != true) {
		std::cout << "\n";
		shop.showAllItems();
		std::cout << "\n------------------------------B A L A N C E------------------------------\n";
		std::cout << "Your Balance: " << characterList[0]->getBalance() << "$";
		std::cout << "\n-------------------------------------------------------------------------\n";

		std::cout << "\nType the id# of an item to purchase... Or [Q] to quit shopping... # ";
		std::cin >> input;
		if (input == "q" || input == "Q") {
			stopShop = true;
		}
		else {
			int id = stoi(input);
			if (id > 0 && id <= shop.getSize()) {
				characterList[0]->addToInv(shop.buyItem(id));
				characterList[0]->setBalance(characterList[0]->getBalance() - shop.buyItem(id)->getPrice());
				std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
				std::cout << "\n----------------------------I N V E N T O R Y----------------------------\n";
				characterList[0]->showInv();
			}
			else {
				std::cout << "That Item was not found in the shop, please try again...\n";
			}
		}
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
		    loadCharacter();
			break;
		}
		else if (input == "e" || input == "E") {
			newCharacter();
			break;
		}
	}
}

void Colloseum::loadCharacter(std::istream& in, std::vector<Character*> cList)
{
    if (!in) {
        std::cout << "File not found";
        exit(10);
    }
    std::string str;
    Character* newCharacter;

    while (in >> newCharacter) {
        cList.push_back(newCharacter);
        //cout << newContact;
    }
}


void Colloseum::newCharacter()
{
	std::cout << "Choose a class: Ninja or Viking... \n";
	std::string input;
	while (std::cin >> input) {
		if (input == "ninja" || input == "Ninja") {

			std::cout << "Choose a name for your ninja: ";
			std::cin >> input;
			characterList.push_back(new Ninja(input, 1000));
			break;
		}
		else if (input == "viking" || input == "Viking") {

			std::cout << "Choose a name for your viking: ";
			std::cin >> input;
			characterList.push_back(new Viking(input, 1000));
			break;
		}
	}
}

void Colloseum::printIntro() {

	std::string p1 = " ________  ________  ___       ________  ________  ________  _______   ___  ___  _____ ______      ";
	std::string p2 = "|\\   ____\\|\\   __  \\|\\  \\     |\\   __  \\|\\   ____\\|\\   ____\\|\\  ___ \\ |\\  \\|\\  \\|\\   _ \\  _   \\    ";
	std::string p3 = "\\ \\  \\___|\\ \\  \\|\\  \\ \\  \\    \\ \\  \\|\\  \\ \\  \\___|\\ \\  \\___|\\ \\   __/|\\ \\  \\\\\\  \\ \\  \\\\\\__\\ \\  \\   ";
	std::string p4 = " \\ \\  \\    \\ \\  \\\\\\  \\ \\  \\    \\ \\  \\\\\\  \\ \\_____  \\ \\_____  \\ \\  \\_|/_\\ \\  \\\\\\  \\ \\  \\|__|\\ \\  \\  ";
	std::string p5 = "  \\ \\  \\____\\ \\  \\\\\\  \\ \\  \\____\\ \\  \\\\\\  \\|____|\\  \\|____|\\  \\ \\  \\_|\\ \\ \\  \\\\\\  \\ \\  \\    \\ \\  \\ ";
	std::string p6 = "   \\ \\_______\\ \\_______\\ \\_______\\ \\_______\\____\\_\\  \\____\\_\\  \\ \\_______\\ \\_______\\ \\__\\    \\ \\__\\";
	std::string p7 = "    \\|_______|\\|_______|\\|_______|\\|_______|\\_________\\_________\\|_______|\\|_______|\\|__|     \\|__|";

	std::cout << p1 << std::endl;
	std::cout << p2 << std::endl;
	std::cout << p3 << std::endl;
	std::cout << p4 << std::endl;
	std::cout << p5 << std::endl;
	std::cout << p6 << std::endl;
	std::cout << p7 << std::endl;

}


