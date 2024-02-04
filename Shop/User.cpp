#include "User.h"
#include "Drinks.h"

User::User(const string &userName) : userName(userName), orders(orders) {
    setUserName(userName);
    setOrders(orders);
}

void User::print() {
    // kolko poruchki sa napraveni
//    std::cout << "Orders for user " << userName << ":\n";
//    for (auto order: orders) {
//        order->print();
//    }
    std::cout << "Client: " << userName << std::endl;
    std::cout << "Orders: " << std::endl;

    for (size_t i = 0; i < orders.size(); ++i) {
        orders[i]->print();
    }
}
//    for (int i = 0; i < orders.size(); ++i) {
//        orders[i]->print();



const string &User::getUserName() const {
    return userName;
}
void User::setUserName(const string &userName) {
    User::userName = userName;
}
const vector<Order *> &User::getOrders() const {
    return orders;
}
void User::setOrders(const vector<Order *> &orders) {
    User::orders = orders;
}

