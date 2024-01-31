#include <iostream>
#include "Book.h"
#include "Member.h"
#include <vector>
#include <string>

using namespace std;

int main() {

    // create books
    Book *book1 = new Book("C++", "Herbert Schildt", "123");
    Book *book2 = new Book("Pod Igoto", "Ivan Vazov", "156");

    std::vector<Book *> book;
    book.push_back(book1);
    book.push_back(book2);

    //create members
    Member member1("Stefan Stefanov", 21, "156548");
    Member member2("Ivan Ivanov", 42, "152635");

    std::vector<Member> members;
    members.push_back(member1);
    members.push_back(member2);

    for (size_t i = 0; i < members.size(); ++i) {
        for (size_t j = book.size() - 1; j > 0; --j) {
            members[i].borrowBook(book[j]);
        }
    }

    return 0;
}
