#ifndef SHOP_ALCOHOLIC_H
#define SHOP_ALCOHOLIC_H

#include "Drinks.h"

class Alcoholic : public Drinks {
public:
    Alcoholic(const string &name, double price, double quantity, int volume, double fee);


    int getVolume() const;
    void setVolume(int volume);
    double getFee() const;
    void setFee(double fee);

    double calculatePrice();
    void print();

private:
    int volume;
    double fee;
};


#endif //SHOP_ALCOHOLIC_H
