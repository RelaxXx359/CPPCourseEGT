#include <iostream>
#include <cmath>
#include "Point.h"
#include <string>
#include "Rectangle.h"

int main(){


    Point p1(5,5);
    Point p2(15,5);
    Point p3(5,15);
    Point p4(15,15);

    Rectangle rect1 (p1,p2,p3,p4);
    std::cout << rect1.displayInfo();
    std::cout << rect1.length();
    std::cout << rect1.width();
    std::cout << rect1.perimeter();
    std::cout << rect1.area();
    std::cout << rect1.isSquare();

    return 0;
}