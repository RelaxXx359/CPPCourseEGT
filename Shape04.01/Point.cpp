#include "Point.h"
#include <iostream>

Point::Point(double x, double y) : x(x), y(y) {}

double Point::getX() const {

    return x;
}

void Point::setX(double x) {
    if (x > 0 && x <= 20) {
        Point::x = x;
    } else {
        this->x = 0;
        std::cout << "Invalid coordinates!" << std::endl;
    }
}

double Point::getY() const {
    return y;
}

void Point::setY(double y) {
    if (x > 0 && x <= 20) {
        Point::y = y;
    } else {
        this->y = 0;
        std::cout << "Invalid coordinates!" << std::endl;
    }
}
