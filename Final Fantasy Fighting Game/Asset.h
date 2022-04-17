/*
* Brian Cook
* CST-210 (3pm)
* 4/3/2022
* My Own Work
*/
#ifndef Asset_H
#define Asset_H

#include <iostream>

class Asset {
private:
    std::string name;
    int id;
public:

    void setName(std::string n) { this->name = n; }
    std::string getName() const { return name; }

    int id() const { return id; }
};

#endif
