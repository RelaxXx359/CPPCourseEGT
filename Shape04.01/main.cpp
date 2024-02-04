#include <iostream>
#include <cmath>


class Rectangle {
public:
    // Constructor, calling a set function for validation
    Rectangle(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4) {
        setCoordinates(x1, y1, x2, y2, x3, y3, x4, y4);
    }

    // Set function for validation of coordinates
    void setCoordinates(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4) {
        if (isValidCoordinates(x1, y1) && isValidCoordinates(x2, y2) &&
            isValidCoordinates(x3, y3) && isValidCoordinates(x4, y4) &&
            isRectangle(x1, y1, x2, y2, x3, y3, x4, y4)) {
            x1_ = x1;
            y1_ = y1;
            x2_ = x2;
            y2_ = y2;
            x3_ = x3;
            y3_ = y3;
            x4_ = x4;
            y4_ = y4;
        } else {
            std::cerr << "Error: Invalid coordinates or do not form a rectangle." << std::endl;
        }
    }

    // Member functions for calculations
    double length() const {
        return std::max(std::abs(x2_ - x1_), std::abs(x4_ - x3_));
    }

    double width() const {
        return std::min(std::abs(y2_ - y1_), std::abs(y4_ - y3_));
    }

    double perimeter() const {
        return 2 * (length() + width());
    }

    double area() const {
        return length() * width();
    }

    // Predicate function to determine if the rectangle is a square
    bool isSquare() const {
        return length() == width();
    }

    // Display information about the rectangle
    void displayInfo() const {
        std::cout << "Coordinates of the rectangle corners: (" << x1_ << ", " << y1_ << "), ("
                  << x2_ << ", " << y2_ << "), (" << x3_ << ", " << y3_ << "), (" << x4_ << ", " << y4_ << ")" << std::endl;
        std::cout << "Length: " << length() << std::endl;
        std::cout << "Width: " << width() << std::endl;
        std::cout << "Perimeter: " << perimeter() << std::endl;
        std::cout << "Area: " << area() << std::endl;
        std::cout << "Is Square: " << (isSquare() ? "Yes" : "No") << std::endl;
    }

private:
    // Function to check the validity of coordinates
    bool isValidCoordinates(double x, double y) const {
        return (x >= 0.0 && y >= 0.0 && x < 20.0 && y < 20.0);
    }

    // Function to check if the coordinates form a rectangle
    bool isRectangle(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4) const {
        return ((x1 == x2 && y1 == y4 && x3 == x4 && y2 == y3) ||
                (x1 == x3 && y1 == y3 && x2 == x4 && y2 == y4));
    }

    // Cartesian coordinates of the four corners of the rectangle
    double x1_;
    double y1_;
    double x2_;
    double y2_;
    double x3_;
    double y3_;
    double x4_;
    double y4_;
};

int main() {
    // Create an object of the Rectangle class with valid coordinates
    Rectangle myRectangle(5.0, 15.0, 5.0, 15.0, 15.0, 15.0, 15.0, 15.0);

    // Call member function to display information about the rectangle
    myRectangle.displayInfo();

    return 0;
}