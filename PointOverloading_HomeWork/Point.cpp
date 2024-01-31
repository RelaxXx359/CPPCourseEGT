#include "Point.h"


Point::Point(int x, int y) {
    setX(x);
    setY(y);
}

void Point::setX(int x) {
    if (x <= 0){
        std::cout << "Invalid number1! Enter a positive number: ";
        std::cin >> x;
    }
    this->x = x;
}
void Point::setY(int y) {
    if (y <= 0){
        std::cout << "Invalid number2! Enter a positive number: ";
        std::cin >> y;
    }
    this->y = y;
}
int Point::getX() const {
    return this->x;
}
int Point::getY() const {
    return this->y;
}

void Point::print() const {
    std::cout << "The coordinates are: " << this->getX() <<  " , " << this->getY() << std::endl;
}


Point operator+(Point p1, Point p2){
    int x = p1.getX() + p2.getX();
    int y = p1.getY() + p2.getY();
    return Point(x,y);
}
Point operator-(Point p1, Point p2){
    int x = p1.getX() - p2.getX();
    int y = p1.getY() - p2.getY();
    return Point(x,y);
}
Point operator*(Point p1, Point p2){
    int x = p1.getX() * p2.getY();
    int y = p1.getY() * p2.getY();
    return Point(x,y);
}
Point operator/(Point p1, Point p2){
    int x = p1.getX() / p2.getX();
    int y = p1.getY() / p2.getY();
    return Point(x,y);
}

