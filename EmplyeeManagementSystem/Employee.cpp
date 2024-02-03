//
// Created by Dobrolyub Velinov on 3.2.2024 г..
//

#include "Employee.h"

Employee::Employee(const string &name , int ID, int position) : name(name), employeeId(ID),
                                         position(position) {}

void Employee::display() {
    cout << "Name: " << getName() << " id " << getPosition() << " position " << getEmployeeId() << endl;
}

const string &Employee::getName() const {
    return name;
}

void Employee::setName(const string &name) {
    Employee::name = name;
}

int Employee::getEmployeeId() const {
    return employeeId;
}

void Employee::setEmployeeId(int employeeId) {
    Employee::employeeId = employeeId;
}

int Employee::getPosition() const {
    return position;
}

void Employee::setPosition(int position) {
    Employee::position = position;
}
