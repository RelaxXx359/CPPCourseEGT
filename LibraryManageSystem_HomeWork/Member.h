#ifndef LIBRARYMANAGESYSTEM_MEMBER_H
#define LIBRARYMANAGESYSTEM_MEMBER_H

#include <iostream>
#include <string>
#include "Book.h"

class Member {
public:
// constructor
    Member(std::string name, int age, std::string member);
// setters
    void setName(std::string);
    void setAge(int);
    void setMemberID(std::string);
// getters
    std::string getName() const;
    int getAge() const;
    std::string getMember() const;
// functions
    void display() const;
    void    borrowBook(Book * book);

private:
// variable
    std::string name;
    int age;
    std::string memberID;
};


#endif //LIBRARYMANAGESYSTEM_MEMBER_H
