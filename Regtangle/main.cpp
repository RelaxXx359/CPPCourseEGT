#include <iostream>
#include "Point.h"
#include "Rectangle.h"
using namespace std;

int main() {
    Point p1(5,5);
    Point p2(15,15);
    Point p3(5,5);
    Point p4(15,15);

    Rectangle rect1 (p1,p2,p3,p4);
    //cout << rect1.isRegtangle() << endl;
    cout << rect1.displayInfo();

    cout << rect1.length();
    cout << rect1.width();
    cout << rect1.parameter();
    cout << rect1.area();
    cout << rect1.isSquare();


//55
//1515
//55
//1515


    return 0;
}
