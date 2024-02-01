#ifndef SHAPE_CIRCLE_H
#define SHAPE_CIRCLE_H

#include "Shape.h"

//create class
class Circle : public Shape {
public:
    //create construction
    Circle(double sideA);
//function
    void draw() override;

};


#endif //SHAPE_CIRCLE_H
