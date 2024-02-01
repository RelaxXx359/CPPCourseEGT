#ifndef POINTOVERLOADING_HOMEWORK_POINT_H
#define POINTOVERLOADING_HOMEWORK_POINT_H
#include <iostream>

class Point {
// friend operators
friend Point operator+ (Point,Point);
friend Point operator-(Point,Point);
friend Point operator*(Point,Point);
friend Point operator/(Point, Point);

public:
    //construction
    Point(int,int);
//setters and getters
    void setX(int);
    void setY(int);
    int getX() const;
    int getY() const;
//function
    void print() const;

private:
    //variable
    int x;
    int y;
};
#endif //POINTOVERLOADING_HOMEWORK_POINT_H
