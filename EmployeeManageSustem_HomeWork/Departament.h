#ifndef EMPLOYEEMANAGESUSTEM_HOMEWORK_DEPARTAMENT_H
#define EMPLOYEEMANAGESUSTEM_HOMEWORK_DEPARTAMENT_H

#include <iostream>
#include "Employee.h"
#include <vector>

class Department {
public:

    Department(std::string, int);

    Department(Department *pDepartment);

    void setDepartmentName(std::string);
    void setNumEmployee(int);

    std::string getDepartmentName();
    int getNumEmployee();

    void addEmployees(Employee *employee);
    void displayEmployes();

private:
    std::string departmentName;
    std::vector<Employee *> employees;
    int numEmployee;
};


#endif //EMPLOYEEMANAGESUSTEM_HOMEWORK_DEPARTAMENT_H
