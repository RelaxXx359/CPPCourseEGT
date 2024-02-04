#include <iostream>
#include "Employee.h"
#include "Departament.h"
#include <vector>
#include <string>

using namespace std;

int main() {
    // create pointers employee
    Employee *ePtr = new Employee("Stefan Stefanov", 2165565, "Manager");
    Employee *e2Ptr = new Employee("Ivan Stefanov", 4644655, "Delivery");

    vector<Employee *> emplo;
    emplo.push_back(ePtr);
    emplo.push_back(e2Ptr);

    // create pointer department
    Department *dPtr = new Department("IT ", 1);

    //create vector departament
    vector<Department *> depart;
    depart.push_back(dPtr);

    //iteration employer
    for (int j = 0; j <  depart.size(); ++j) {
        depart[j]->displayEmployes();
        for (int i = 0; i < emplo.size(); ++i) {
            emplo[i]->display();
        }
    }

//    dPtr->addEmployees(ePtr);
//    dPtr->addEmployees(e2Ptr);
//    dPtr->displayEmployes();
    return 0;
}
