#include <iostream>
#include <string>

class Shape {
public:   
	 Shape(const std::string color) : color(color){}
	 ~Shape() {};
	 void draw() const {};


protected:
	std::string color;
};

class Circle : public Shape {
public:
	Circle(const std::string color ) : Shape(color){}
	void draw() const {
		std::cout << "Drawing a "<< color << " circle" << std::endl;
	} 

};
class Rectangle :public Shape {
public:
	Rectangle(const std::string color) : Shape(color){}
	void draw() const  {
		std::cout << "Drawing a " << color <<  " rectangle" << std::endl;
	}

};

int main() {

	Circle c1("red");
	Rectangle r1("blue");

	c1.draw();
	r1.draw(); 

	return 0;
}