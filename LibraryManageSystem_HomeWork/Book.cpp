#include "Book.h"
//construction
Book::Book(std::string title, std::string name, std::string isbn) {
    setTitle(title);
    setTitle(name);
    setISBN(isbn);
}
//function
void Book::display() const {
    std::cout << "Title:" <<this->title << " " << " Name: "<< this->autor << " " << "ISBN"<< this->ISBN << std::endl;
}

//setters
void Book::setTitle(std::string t) {
    title = t;
}
void Book::setAutor(std::string a) {
    autor = a;
}
void Book::setISBN(std::string isbn) {
    ISBN = isbn;
}


// getters
std::string Book::getTitle() {
    return title;
}
std::string Book::getAutor() {
    return autor;
}
std::string Book::getISBN() {
    return ISBN;
}

