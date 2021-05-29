#include "Strategy.hpp"
#include "User.hpp"
#include <string>
#include <vector>
#include <iostream>
#include <map>
#include "Library.hpp"
#include "Standard.hpp"

void Standard::run(Library* library_system) {}

void Standard::newList(Library* library) {
	Composition* newList = new Composition();
	
	std::string name;
	std::cout << "List name: ";
	std::getline(std::cin, name);
	newList->SetName(name);
	std::cin.clear();

	int input = 1;
	while (input != 0) {
		std::cout << "1. Output List" << std::endl;
		std::cout << "2. Add to List" << std::endl;
		std::cout << "0. Stop" << std::endl;

		std::cin >> input;
		if (input == 1) {
			library->DisplayAll();
		}
		else if (input == 2) {
			std::cout << "Enter an ID number or press 2 to enter another list: ";
			std::cin >> input;
			if (input != 2) {
				for (auto i : library->GetLibrary()) {
					if (i->GetID() == input) {
						Individual* entry = new Individual();
						entry->SetBook(library->FindBook(input));
						newList->Add(entry);
						std::cout << entry->GetBook()->GetTitle() << " was added to your list" << std::endl;
					}
				}
			}
			else {
				if (lists.size() != 0) {
					std::cout << "Enter name of list you would like to add: ";
					std::getline(std::cin, name);
					std::cin.clear();
					for (auto i : lists) {
						if (name == i->GetName()) {
							newList->Add(i);
							std::cout << name << " was added to your list" << std::endl;
						}
					}
				}
				else {
					std::cout << "Error: No Lists available" << std::endl;
				}
			}
		}
	}
}

void Standard::viewLists() {
	for (auto i : lists) {
		i->print(0);
	}
}

void Standard::recommend(std::vector<Book*> library) {
	int input;
	std::cout << "Would you like recommendations based off of 1. favorites or 2. most popular?" << std::endl;
	std::cin >> input;

	if (input == 1) {
		Favorites* alg = new Favorites();
		alg->recommendation_algorithm(history, library);
	}
	else {
		Popular* alg = new Popular();
		alg->recommendation_algorithm(history, library);
	}

}

void Standard::AddCheckedOut(Book* book) {
	checkedOut.push_back(book);
}

void Standard::AddHistory(std::pair<Book*, double> data) {
	history.insert(data);
}

void Standard::AddLists(Composition* list) {
	lists.push_back(list);
}

void Standard::checkoutBook(Book* b, std::vector<Book*>& library) {
	bool bookFound = false;
	int index = 0;
	for (int i = 0; i < library.size(); i++) {
		if (library.at(i)->GetID() == b->GetID()) {
			index = i;
			bookFound = true;
		}
	}
	if (bookFound) {
		library.erase(library.begin() + index);
		checkedOut.push_back(b);
		std::cout << "Book with ID: " << b->GetID() << " has been successfully checked out to User." << std::endl;
	}
	else {
		std::cout << "Book with ID: " << b->GetID() << " was not found in the Library." << std::endl;
	}
}

void Standard::returnBook(Book* b, std::vector<Book*>& library, int index) {
	double rating;
	checkedOut.erase(checkedOut.begin() + index);
	library.push_back(b);
	std::cout << "Book with ID: " << b->GetID() << " has been successfully returned to the Library." << std::endl;
	std::cout << "From 1 to 5 (1 being the worst, 5 being the best), please input your rating of this book: ";
	std::cin >> rating;
	std::cout << std::endl;
	this->history.insert(std::pair<Book*, double>(b, rating));
	std::cout << "You have given the book with ID: " << b->GetID() << " a rating of " << rating << "." << std::endl;
}

void Standard::displayBooks() {
    for(unsigned i = 0; i < checkedOut.size(); i++) {
       std::cout <<  checkedOut.at(i)->GetTitle() << std::endl;
    }
}
