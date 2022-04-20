#include "Sword.h"

Sword::Sword()
{
	this->name = "null";
	this->damage = 35;
}

Sword::Sword(std::string n, int d, int price, int id)
{
	this->name = n;
	this->damage = d;
	setPrice(price);
	setId(id);
}
