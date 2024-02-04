#include "Alcoholic.h"


Alcoholic::Alcoholic(const string &name, double price, double quantity, int volume, double fee)
        : Drinks(name, price, quantity), volume(volume), fee(fee) {
    setVolume(volume);
    setFee(fee);

}


//void Alcoholic::print() {
//    cout << "Name: " << getName() << ", price: " << getPrice() << ", quantity " << getQuantity() << ", volume: " << volume << ", fee: " << fee << endl;
//}

double Alcoholic::calculatePrice() {
    return  getQuantity() * getPrice() * getFee();
}

int Alcoholic::getVolume() const {
    return volume;
}

void Alcoholic::setVolume(int volume) {
    Alcoholic::volume = volume;
}

double Alcoholic::getFee() const {
    return fee;
}

void Alcoholic::setFee(double fee) {
    Alcoholic::fee = fee;
}
