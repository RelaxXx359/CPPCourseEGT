#include <iostream>
#include "Point.h"
int main() {

    Point p1(20, 30);
    Point p2(10, 10);

    //gathering
    Point p3 = p1 + p2;
    //subtraction
    Point p4 = p1 - p2;
    //multiplication
    Point p5 = p2 * p4;
    //division
    Point p6 = p1 / p4;

    p1.print();
    p2.print();
    p3.print();
    p4.print();
    p5.print();
    p6.print();

    return 0;
}
