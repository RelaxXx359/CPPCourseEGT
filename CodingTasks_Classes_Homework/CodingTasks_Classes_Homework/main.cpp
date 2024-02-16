#include <iostream>
#include <string>
class Book {
public:
	// конструктор за инициализиране на атрибути
	Book(std::string title, std::string author, int pages) :
		title(title), author(author), pages(pages) {}

	// Функция за отпечатване
	void display() {
		std::cout << "Title: " << title << std::endl;
		std::cout << "Autor: " << author << std::endl;
		std::cout << "Pages: " << pages << std::endl;
	}

private:
	std::string title;   // Заглавие на книгата
	std::string author;  // Автор на книгата
	int pages; // Брой страници на книгата
};


int main() {

	Book book1("Pod igoto", "Ivan Vazov", 58);

	book1.display();


	return 0;
}