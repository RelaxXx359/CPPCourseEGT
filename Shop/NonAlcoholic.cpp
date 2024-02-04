#include "NonAlcoholic.h"

NonAlcoholic::NonAlcoholic(const string &name, double price, double quantity, int volume, double cityFee)
: Drinks(name,price,quantity),volume(volume),cityFee(cityFee) {}


//void NonAlcoholic::print() {
//    cout << "Name: " << getName() << ", price: " << getPrice() << ", quantity " << getQuantity() << ", volume: " << volume << ", fee: " << cityFee << endl;
//}
double NonAlcoholic::calculatePrice() {

    return getQuantity() * getPrice() + cityFee;
}

int NonAlcoholic::getVolume() const {
    return volume;
}
void NonAlcoholic::setVolume(int volume) {
    NonAlcoholic::volume = volume;
}
double NonAlcoholic::getCityFee() const {
    return cityFee;
}
void NonAlcoholic::setCityFee(double cityFee) {
    NonAlcoholic::cityFee = cityFee;
}


