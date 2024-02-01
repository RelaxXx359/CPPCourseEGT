#include "Regtangle.h"

//create construction
Regtangle::Regtangle(double sideA, double sideB): Shape(sideA) {
    setSideA(sideA);
    setSideB(sideB);
}
//creaete function
void Regtangle::draw() {
    std::cout << "Drawing a Regtangle." << std::endl;
}

//setter
double Regtangle::setSideB(double sideB) {
    if (sideB < 0){
        std::cout << "Invalid number" << std::endl;
        std::cin >> sideB;
    }
    return Shape::getSideA() * sideB;
}
//getter
double Regtangle::getSideB() {
    return sideB;
}
