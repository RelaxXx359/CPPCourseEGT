#include "Departament.h"
//constructor
Department::Department(std::string name, int num) {
    setDepartmentName(name);
    setNumEmployee(num);
    employees = new Employee*[10];
}
//finction
void Department::displayEmployes() {
    std::cout << "Employee is Departament " << departmentName <<  ":" << std::endl;
    for (int i = 0; i < numEmployee; ++i) {
        employees[i]->display();
    }
}
void Department::addEmployees(Employee *employee) {
    if (numEmployee < 2) {
        employees[numEmployee] = employee;
        numEmployee++;
    } else
        std::cout << "Departament is full" << std::endl;
}
//setters

void Department::setDepartmentName(std::string name) {
    this->departmentName = name;
}
void Department::setNumEmployee(int num) {
    this->employees;
}
//getters
std::string Department::getDepartmentName() {
    return departmentName;
}
int Department::getNumEmployee() {
    return numEmployee;
}
Department::Department(Department *pDepartment) {

}
