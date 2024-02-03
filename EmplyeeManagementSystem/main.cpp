#include <iostream>
#include <string>

using namespace std;

#include "Employee.h"
#include "Departament.h"

int main() {

    Employee *ePtr = new Employee("Stefan Stefanov, 25, 562");
    Employee *e2Ptr = new Employee("Ivan Stefanov, 45, 654");

    vector<Employee* > emplo;
    emplo.push_back(ePtr);
    emplo.push_back(e2Ptr);

    Departament *dPtr = new Departament("Ofis ", 15);

    vector<Departament *> depart;
    depart.push_back(dPtr);

    for (int i = 0; i < emplo.size(); ++i) {
        cout << "Departament" << endl;
        for (int j = 0; j < depart.size(); ++j) {
            emplo[i]->display();
            depart[j]->displayEmployees();
        }
    }






    return 0;
}
