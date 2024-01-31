#ifndef EMPLOYEEMANAGESUSTEM_HOMEWORK_EMPLOYEE_H
#define EMPLOYEEMANAGESUSTEM_HOMEWORK_EMPLOYEE_H

#include <iostream>

class Employee {
public:
    Employee(std::string, int= 0, int = 0);

    void setName(std::string);
    void setEmployee(int);
    void setPosition(int);

    std::string getName() const;
    int getEmployee() const;
    int getPosition() const;

    void display() const;

private:
    std::string name;
    int employeeID;
    int position;

};


#endif //EMPLOYEEMANAGESUSTEM_HOMEWORK_EMPLOYEE_H
