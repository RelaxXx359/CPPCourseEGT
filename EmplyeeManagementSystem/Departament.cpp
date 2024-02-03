
#include "Departament.h"

Departament::Departament(const string &departamenName, int numEmployee)
        : departamenName(departamenName), numEmployee(numEmployee) {}

void Departament::displayEmployees() {
    cout << "Name: " << getDepartamenName() << " num employee " << getNumEmployee() << endl;
    for (auto employee: employees) {
        employee->display();
    }
}
void Departament::addEmployees(Employee * employee) {
//    int num;
//    employees.push_back(employee);
//    numEmployee++;
if (numEmployee > 10){
    employees[employee] = employee;
    numEmployee++;
}else{
    std::cout
}
}



const string &Departament::getDepartamenName() const {
    return departamenName;
}
void Departament::setDepartamenName(const string &departamenName) {
    Departament::departamenName = departamenName;
}
int Departament::getNumEmployee() const {
    return numEmployee;
}
void Departament::setNumEmployee(int numEmployee) {
    Departament::numEmployee = numEmployee;
}
