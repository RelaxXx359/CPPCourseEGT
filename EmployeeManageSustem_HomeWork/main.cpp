#include <iostream>
#include "Employee.h"
#include "Departament.h"
#include <vector>
int main() {
// create pointers employee
    Employee *firstEmployee = new Employee("Ivan Petrov", 10235, 156);
    Employee *secondEmployee = new Employee("Georgi Stoilov", 25463, 485);

    std::vector<Employee*> employees;
    employees.push_back(firstEmployee);
    employees.push_back(secondEmployee);

    // create pointers departments
    Department *firstDepartment = new Department("Some kind of job", 12);
    Department *secondDepartment = new Department("Concrete junction",32);

    //create vector departament
    std::vector<Department> department;
    department.push_back(firstDepartment);
    department.push_back(secondDepartment);

    //iteration employer
    for (size_t i = 0; i < employees.size(); ++i) {
        //iteration departament
        for (size_t j = department.size() - 1; j > 0; --j) {
            employees[i]->display();
            department[i].displayEmployes();
        }
    }

    return 0;
}
