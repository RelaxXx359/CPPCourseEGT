#pragma once

#include <string>
#include "Workstation.h"
#include <iostream>

using namespace std;

class Employee {

public:
	Employee(string, string, int, Workstation*);
	static Employee* parseEmployee(pugi::xml_node);

	friend ostream& operator<<(ostream& os, const Employee& employee);
	
private:
	string name;
	string type;
	int age;
	Workstation* workstation;
};