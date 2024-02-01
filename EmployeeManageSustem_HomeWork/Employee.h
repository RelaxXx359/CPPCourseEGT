#ifndef EMPLOYEEMANAGESUSTEM_HOMEWORK_EMPLOYEE_H
#define EMPLOYEEMANAGESUSTEM_HOMEWORK_EMPLOYEE_H

#include <iostream>

class Employee {
public:

    //construction
    Employee(std::string, int= 0, int = 0);
//setters
    void setName(std::string);
    void setEmployee(int);
    void setPosition(int);
//getters
    std::string getName() const;
    int getEmployee() const;
    int getPosition() const;
//function
    void display() const;

private:
    //variable
    std::string name;
    int employeeID;
    int position;

};


#endif //EMPLOYEEMANAGESUSTEM_HOMEWORK_EMPLOYEE_H
