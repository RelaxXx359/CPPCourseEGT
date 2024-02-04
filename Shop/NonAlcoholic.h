#ifndef SHOP_NONALCOHOLIC_H
#define SHOP_NONALCOHOLIC_H
#include "Drinks.h"

class NonAlcoholic: public Drinks{
public:
    NonAlcoholic(const string &name, double price, double quantity, int volume, double cityFee);

    int getVolume() const;
    void setVolume(int volume);
    double getCityFee() const;
    void setCityFee(double cityFee);

    void print();
    double calculatePrice();

private:
    int volume;
    double cityFee;

};


#endif //SHOP_NONALCOHOLIC_H
