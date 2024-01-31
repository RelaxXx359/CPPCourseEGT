#ifndef POINTOVERLOADING_HOMEWORK_POINT_H
#define POINTOVERLOADING_HOMEWORK_POINT_H
#include <iostream>

class Point {

friend Point operator+ (Point,Point);
friend Point operator-(Point,Point);
friend Point operator*(Point,Point);
friend Point operator/(Point, Point);

public:
    Point(int,int);

    void setX(int);
    void setY(int);
    int getX() const;
    int getY() const;

    void print() const;

private:
    int x;
    int y;
};
#endif //POINTOVERLOADING_HOMEWORK_POINT_H
