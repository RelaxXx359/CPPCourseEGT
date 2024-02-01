
#ifndef DATE_BOX_H
#define DATE_BOX_H
#include "Date.h"

class Box {

//    friend ostream &operator>>( ostream &, const Date & );
    friend Box operator+(Box, Box);
public:
    //construction
    Box(double width, double length, double height);

//setters
    void setWidth(double width);
    void setLength(double length);
    void setHeight(double height);
//getters
    double getWidth() ;
    double getLength() ;
    double getHeight() ;
//function
    void print();

private:
    //variable
    double width;
    double length;
    double height;

};


#endif //DATE_BOX_H
