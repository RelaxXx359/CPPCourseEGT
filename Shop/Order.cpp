#include "Order.h"

Order::Order(int drinks, int date, double totalPrice) : drinks(drinks), date(date), totalPrice(totalPrice) {}



double Order::calculatePrice() {
}
// kolko napitka sa prodadeni
int Order::getDrinks() const {
    int totalDrinks = 0;
    for (int i = 0; i < drinks; ++i) {
        totalDrinks++;
    }
    return totalDrinks;
}

void Order::setDrinks(int drinks) {
    Order::drinks = drinks;
}
int Order::getDate() const {
    return date;
}
void Order::setDate(int date) {
    Order::date = date;
}

// kolko napitka sa prodadeni
//double Order::getTotalPrice( double orders) const {
//    double totalOrders = 0;
//    for (auto order: orders) {
//        totalOrders += order->calculatePrice();
//    }
//    for (int i = 0; i < orders.size(); ++i) {
//        orders[i]->print();
//    }
//    return totalOrders;
//}
void Order::setTotalPrice(double totalPrice) {
    Order::totalPrice = totalPrice;
}
