#ifndef SHOP_DRINKS_H
#define SHOP_DRINKS_H

#include <iostream>
#include <string>

using namespace std;

class Drinks {
public:
    Drinks(const string &name, double price, double quantity);

    virtual void print();
    virtual double calculatePrice();


    const string &getName() const;
    void setName(const string &name);
    double getPrice() const;
    void setPrice(double price);
    double getQuantity() const;
    void setQuantity(double quantity);


private:
    string name;
    double price;
    double quantity;
};


#endif //SHOP_DRINKS_H
