#include "Employee.h"

Employee::Employee(string name, string type, int age, Workstation *workSt):
	name(name), type(type), age(age), workstation(workSt){
}
Employee* Employee::parseEmployee(pugi::xml_node emplNode) {
	string name = emplNode.attribute("Name").value();
	string type = emplNode.attribute("Type").value();
	int age = emplNode.attribute("Age").as_int();


	Workstation *wPrt = Workstation::parseWorkstation(emplNode.child("Workstation"));

	return new Employee(name, type, age, wPrt);
}

ostream& operator<<(ostream& os, const Employee& employee) {
	os << "Name: " << employee.name << " Type: " << employee.type << " Age: " << employee.age << " Workstation: "
		<< employee.workstation;
	return os;
}