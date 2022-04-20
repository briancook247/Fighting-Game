#include "Bow.h"

Bow::Bow()
{
	this->name = "null";
	this->damage = 35;
}

Bow::Bow(std::string n, int d, int price, int id)
{
	this->name = n;
	this->damage = d;
	setPrice(price);
	setId(id);
}
