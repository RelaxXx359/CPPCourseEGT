#ifndef SHAPE_REGTANGLE_H
#define SHAPE_REGTANGLE_H
#include "Shape.h"


//create class with inheritance
class Regtangle : public Shape{
public:
    //create construction
    Regtangle(double sideA, double sideB);
//setter and getter
    double setSideB(double sideB);
    double getSideB();
//function
    void draw() override;

private:
    //create variable
    double sideB;

};


#endif //SHAPE_REGTANGLE_H
