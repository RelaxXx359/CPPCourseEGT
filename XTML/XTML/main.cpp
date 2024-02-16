#include <iostream>
#include "pugixml.h"
#include "EmployeeService.h"

int main() {

	EmployeeService::parsenEmployeeData();

	for (auto employee : EmployeeService::getEmployeeList()) {
		cout << *employee << endl;
	}

	return 0;
}