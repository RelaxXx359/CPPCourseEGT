#pragma once
#include <vector>
#include "Employee.h"

class EmployeeService {
public:
	static void parsenEmployeeData();
	static std::vector<Employee*> getEmployeeList();

	friend ostream& operator<<(ostream& os, const EmployeeService& service);


private:
	static std::vector<Employee*> employeeList;
	static pugi::xml_document doc;
};