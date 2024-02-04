#include "Point.h"
#include "Rectangle.h"


Rectangle::Rectangle(const Point &p1, const Point &p2, const Point &p3, const Point &p4)
        : p1(p1), p2(p2), p3(p3), p4(p4) {}

double Rectangle::displayInfo() {
    std::cout << "Coordinates of the rectangle corners: (" << p1.getX() << ", " << p1.getY() << "), (" << p2.getX() << ", " << p2.getY() << "), ("
    << p3.getX() << ", " << p3.getY() << "), (" << p4.getX() << ", " << p4.getY() << ")"<< std::endl;
    std::cout << "Length: " << length() << std::endl;
    std::cout << "Width: " << width() << std::endl;
    std::cout << "Parameter: " << parameter() << std::endl;
    std::cout << "Area: " << area() << std::endl;
    std::cout << "Is square: " << (isSquare() ? "Yes" : "No" ) << std::endl;

}

bool Rectangle::isRegtangle() {
    // ПРОВЕРКА ДАЛИ  E ПРАВОЪГЪЛНИКА
    if (this->p1.getX() + this->p3.getX() != this->p2.getX() + this->p3.getX()) {
        return true;
    }
    return false;
}

double Rectangle::length() {
    return std::max(std::abs(p2.getX() - p1.getX()), std::abs(p4.getX() - p3.getX()));
}

double Rectangle::width() {
    return std::min(std::abs(p2.getY() - p1.getY()), std::abs(p4.getY() - p3.getY()));
}

double Rectangle::parameter() {
    return 2 * (length() + width());
}

// second is always greater
double Rectangle::area() {
    return length() * width();
}

bool Rectangle::isSquare() {
    return length() == width();
}


const Point &Rectangle::getP1() const {
    return p1;
}

void Rectangle::setP1(const Point &p1) {
    Rectangle::p1 = p1;
    //this->p1 = p1;
}

const Point &Rectangle::getP2() const {
    return p2;
}

void Rectangle::setP2(const Point &p2) {
    Rectangle::p2 = p2;
    //this->p2 = p2;
}

const Point &Rectangle::getP3() const {
    return p3;
}

void Rectangle::setP3(const Point &p3) {
    Rectangle::p3 = p3;
    //    this->p3 = p3;
}

const Point &Rectangle::getP4() const {
    return p4;
}

void Rectangle::setP4(const Point &p4) {
    Rectangle::p4 = p4;
    //    this->p4 = p4;
}
