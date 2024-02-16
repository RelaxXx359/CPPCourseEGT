#include <iostream>
#include <string>
class Book {
public:
	// constructor  initialize attributes
	Book(std::string title, std::string author, int pages) :
		title(title), author(author), pages(pages) {}

	// function of print
	void display() {
		std::cout << "Title: " << title << std::endl;
		std::cout << "Autor: " << author << std::endl;
		std::cout << "Pages: " << pages << std::endl;
	}

private:
	// member varaible
	std::string title;   
	std::string author; 
	int pages; 
};


int main() {
	// class object
	Book book1("Pod igoto", "Ivan Vazov", 58);

	//print object
	book1.display();


	return 0;
}