
#include "Drinks.h"

Drinks::Drinks(const string &name, double price, double quantity) : name(name), price(price),
                                                                                        quantity(quantity){}


double Drinks::calculatePrice() {

    return quantity * price;
}
void Drinks::print(){
    cout << "Name " << name << "price: " << price << " " << "number" << quantity << endl;
}

const string &Drinks::getName() const {
    return name;
}
void Drinks::setName(const string &name) {
    Drinks::name = name;
}
double Drinks::getPrice() const {
    return price;
}
void Drinks::setPrice(double price) {
    Drinks::price = price;
}
double Drinks::getQuantity() const {
    return quantity;
}
void Drinks::setQuantity(double quantity) {
    Drinks::quantity = quantity;
}

