#include "EmployeeService.h"

pugi::xml_document EmployeeService::doc;
std::vector<Employee*> EmployeeService::employeeList;

void EmployeeService::parsenEmployeeData() {
	//open file
	//go to EmployeeDate.Employees node
	//loop tru Employee
	//read the Employee node -> parsenEmployee; return employee(Employee object)
	//add employeen object to vector
	if (!doc.load_file("sample.xml")) {
		return;
	}
	pugi::xml_node employees = doc.child("EmployeesDate").child("Employees");


	/*for (pugi::xml_node employee = employees.child("Employee"); 
		                employee;
		                employee = employee.next_sibling("Employee")){
	}*/

	for (auto employee : employees) {
		Employee* ePtr = Employee::parseEmployee(employee);
		employeeList.push_back(ePtr);

	}
	 
	ostream& operator<<(ostream & os, const EmployeeService & service) {
		return os;
	}
}