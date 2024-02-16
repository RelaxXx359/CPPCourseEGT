#include <iostream>
#include <string>

class Shape {
public:
   //constriction
	Shape(const std::string color):color(color) {

	}
   //destructor
	virtual ~Shape() {};

	//virtual function
	virtual void draw() const {};
	virtual double area() const { return 0; };
public:
	//member varialbe
	std::string color;
};



class Circle : public Shape {
public:
	//constriction
	Circle(const std::string color, double radios) : Shape(color), radios(radios) {}
	

	//function
	void draw() const override {
		std::cout << "Drawing a " << color << " circle" <<std::endl;
	}
	//function 
	double area() const override{
		return 3,14 * radios * radios;
	}
private:
	//member viraible
	double radios;
};


class Rectangle :public Shape {
public:
	//constriction
	Rectangle(const std::string color, double width, double height) : Shape(color), width(width), height(height){}

	//function
	void draw() const override {
		std::cout << "Drawing a " << color << " rectangle" <<  std::endl;
	}
	//function
	double area() const override {
		return width * height;
	}
	
public:
	// member varaible
	double width;
	double height;
};

    //a function that takes a pointeр
void printArea(Shape* sPtr) {
	std::cout << sPtr->area() << std::endl;
}

int main() {
	// class object
	Circle c1("red", 10);
	Rectangle r1("blue", 4, 5);

	//function call
	c1.draw();
	r1.draw();

	//a function that accepts a pointer
	printArea(&c1);
	printArea(&r1);


	return 0;
}