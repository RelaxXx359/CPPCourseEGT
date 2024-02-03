#ifndef EMPLOYEEMANAGESUSTEM_HOMEWORK_DEPARTAMENT_H
#define EMPLOYEEMANAGESUSTEM_HOMEWORK_DEPARTAMENT_H

#include <iostream>
#include "Employee.h"
#include <vector>

class Department {
public:
//construction
    Department(std::string, int);

    Department(Department *pDepartment);
//setters
    void setDepartmentName(std::string);
    void setNumEmployee(int);
//getters
    std::string getDepartmentName();
    int getNumEmployee();
//function
    void addEmployees(Employee *employee);
    void displayEmployes();

private:
    //variable
    std::string departmentName;
    Employee** employees;
    int numEmployee;
};


#endif //EMPLOYEEMANAGESUSTEM_HOMEWORK_DEPARTAMENT_H
