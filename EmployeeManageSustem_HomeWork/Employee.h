#ifndef EMPLOYEEMANAGESUSTEM_HOMEWORK_EMPLOYEE_H
#define EMPLOYEEMANAGESUSTEM_HOMEWORK_EMPLOYEE_H

#include <iostream>

class Employee {
public:

    //construction
    Employee(std::string, int , std::string);
//setters
    void setName(std::string);
    void setEmployee(int);
    void setPosition(std::string);
//getters
    std::string getName() const;
    int getEmployee() const;
    std::string getPosition() const;
//function
    void display() const;

private:
    //variable
    std::string name;
    int employeeID;
    std::string position;

};


#endif //EMPLOYEEMANAGESUSTEM_HOMEWORK_EMPLOYEE_H
