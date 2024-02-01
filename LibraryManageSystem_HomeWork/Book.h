#ifndef LIBRARYMANAGESYSTEM_BOOK_H
#define LIBRARYMANAGESYSTEM_BOOK_H
#include <iostream>

class Book {
public:
    //construction
    Book(std::string, std::string, std::string);

    //setters
    void setTitle(std::string);
    void setAutor(std::string);
    void setISBN(std::string);

    //getters
    std::string getTitle();
    std::string getAutor();
    std::string getISBN();

    //function
    void display() const;


private:
    //variable
    std::string title;
    std::string autor;
    std::string ISBN;

};


#endif //LIBRARYMANAGESYSTEM_BOOK_H
