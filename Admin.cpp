#include <string>
#include <vector>
#include "Standard.hpp"
#include "Library.hpp"
#include "Admin.hpp"
#include <iostream>

Admin::Admin(const std::string& uname, const std::string& pass) : Standard(uname, pass) {}

void Admin::run(Library*){}

void Admin::addBook(Book* b, std::vector<Book*>& library) {
	library.push_back(b);
	std::cout << "Book was successfully added to Library." << std::endl;
}
void Admin::remBook(Book* b, std::vector<Book*>& library) {
	bool bookFound = false;
	int index = 0;
	for (int i = 0; i < library.size(); i++) {
		if (library.at(i)->GetID() == b->GetID()) {
			index = i;
			bookFound = true;
		}
	}
	if (bookFound) {
		library.erase(library.begin() + index - 1);
		std::cout << "Book was successfully removed from Library." << std::endl;
	}
	else {
		std::cout << "Book was not found in Library." << std::endl;
	}
}
