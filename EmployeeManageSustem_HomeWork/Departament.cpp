#include "Departament.h"
//constructor
Department::Department(std::string name, int num) {
    setDepartmentName(name);
    setNumEmployee(num);
}
//finction
void Department::displayEmployes() {
    std::cout << "Name " << getDepartmentName() << " number: " << getNumEmployee() << std::endl;
    for (auto employee: employees) {
        employee->display();

    }
}
//setters
void Department::addEmployees(Employee *employee) {
    int num;
    employees.push_back(employee);
    num++;
}
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
