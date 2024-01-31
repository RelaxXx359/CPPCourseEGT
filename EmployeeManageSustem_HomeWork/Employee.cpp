#include "Employee.h"

Employee::Employee(std::string name, int ID, int position) {
    setName(name);
    setEmployee(ID);
    setPosition(position);
}

void Employee::display() const{
    std::cout << "Name: " << getName() << "ID:" << getEmployee() << "Position: " << getPosition() << std::endl;
}

void Employee::setName(std::string n) {
    this->name = n;
}
void Employee::setEmployee(int id) {
    this->employeeID = id;
}
void Employee::setPosition(int possition) {
    this->position = possition;
}


std::string Employee::getName() const {
    return name;
}
int Employee::getEmployee() const {
    return employeeID;
}
int Employee::getPosition() const{
    return position;
}