#include "Member.h"

//construction
Member::Member(std::string name, int age, std::string member) {
    setName(name);
    setAge(age);
    setMemberID(member);

}
// functions
void Member::display() const {
    std::cout << "Name: " << this->getName() << ", age: " << this->getAge() << ", member id: "
              << this->getMember() << std::endl;
}
void Member::borrowBook(Book *book) {
    std::cout << "Member ";
    this->display();
    std::cout << "Borrow book: ";
    book->display();
}

//setters
void Member::setName(std::string name) {
    this->name = name;
}
void Member::setAge(int age) {
    this->age = age;
}
void Member::setMemberID(std::string member) {
    this->memberID = member;
}

//getters
std::string Member::getName() const {
    return name;
}
int Member::getAge() const{
    return age;
}
std::string Member::getMember() const{
    return memberID;
}

