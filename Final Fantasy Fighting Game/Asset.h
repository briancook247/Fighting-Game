/*
* Brian Cook
* CST-210 (3pm)
* 4/3/2022
* My Own Work
*/
#ifndef Asset_H
#define Asset_H

#include <iostream>
#include <iomanip>

class Asset {
private:
    int id;
    int price;
public:
    void setId(int id) { this->id = id; }
    int getId() const { return id; }
    void setPrice(int price) { this->price = price; }
    int getPrice() const { return price; }
    virtual void getItemInfo() = 0;

};

#endif
