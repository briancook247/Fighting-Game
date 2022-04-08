/*
* Brian Cook
* CST-210 (3pm)
* 4/3/2022
* My Own Work
*/
#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>

class Character {
private:
    std::string name;
    double maxHealth;
    double health;
public:

    void setName(std::string n) { this->name = n; }
    std::string getName() const { return name; }
    void setMaxHealth(double newMaxHealth) { this->maxHealth = newMaxHealth; }
    double getMaxHealth() const { return maxHealth; }
    void setHealth(double newHealth) { this->health = newHealth; }
    double getHealth() const { return health; };
    virtual void eat() = 0;
    virtual void speak() = 0;  
    virtual std::string getSpecies() = 0;
    virtual double getTopWeight() = 0;
};

#endif
