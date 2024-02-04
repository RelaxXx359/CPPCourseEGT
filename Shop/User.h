#ifndef SHOP_USER_H
#define SHOP_USER_H

#include <iostream>
#include <vector>
#include "Order.h"

class User {
public:
    User(const std::string &userName);

    const std::string &getUserName() const;

    void setUserName(const std::string &userName);

    const std::vector<Order *> &getOrders() const;

    void setOrders(const std::vector<Order *> &orders);

    void print();

private:
    std::string userName;
    std::vector<Order*> orders;

};


#endif //SHOP_USER_H
