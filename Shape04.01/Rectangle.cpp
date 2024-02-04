#include "Rectangle.h"
#include "Point.h"
#include <iostream>

Rectangle::Rectangle(const Point &p1, const Point &p2, const Point &p3, const Point &p4) : p1(p1), p2(p2), p3(p3),
                                                                                           p4(p4) {}
// изчисляване на дължина и ширина
//void calculateDimensions(double length, double width) {
//    length = std::max(std::abs( - p2), std::abs(p4 - p3));
//    width = std::min(std::abs(y2_ - y1_), std::abs(y4_ - y3_));
//}

// Член-функции за изчисляване на периметър и площ
double perimeter(double length, double width) {
    return 2 * (length + width);
}

bool Rectangle::isSquare() {
    if (isRectangle()) {
        if(calculate(p1.getX(), p2.getX() == (p1.getY(), p3.getY()))){

            return true;
        }
    }
    return false;
}


const Point &Rectangle::getP1() const {
    return p1;
}

void Rectangle::setP1(const Point &p1) {
    Rectangle::p1 = p1;
}

const Point &Rectangle::getP2() const {
    return p2;
}

void Rectangle::setP2(const Point &p2) {
    Rectangle::p2 = p2;
}

const Point &Rectangle::getP3() const {
    return p3;
}

void Rectangle::setP3(const Point &p3) {
    Rectangle::p3 = p3;
}

const Point &Rectangle::getP4() const {
    return p4;
}

void Rectangle::setP4(const Point &p4) {
    Rectangle::p4 = p4;
}
