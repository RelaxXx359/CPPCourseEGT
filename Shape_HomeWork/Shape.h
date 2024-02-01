#ifndef SHAPE_SHAPE_H
#define SHAPE_SHAPE_H

#include <iostream>
//creaete class
class Shape {
public:
    //create construction
    Shape(double sideA);
    //virtual method
    virtual void draw();
//getter and setter
    void setSideA(double);
    double getSideA();

private:
    //create variable
    double sideA;
};

#endif //SHAPE_SHAPE_H
