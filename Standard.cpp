#include "Standard.hpp"
#include "Library.h"
#include <string>
#include <vector>
#include <iostream>

Standard::Standard(std::string name) {
   this->setID(name);
}  

void Standard::run() {}
void Standard::recommend() {}
void Standard::checkoutBook(Book* b) {
	bool bookFound = false;
	for (int i = 0; i < library.size(); i++) {
		if (library.at(i)->GetID() == b->GetID()) {
			library.erase(library.begin() + i - 1);
			bookFound = true;
		}
	}
	if (bookFound) {
		checkedOut.push_back(b);
	}
	else {
		//Book was not found in Library.
	{
}
void Standard::returnBook(Book* b) {

}
void Standard::displayBooks() {
    for(unsigned i = 0; i < checkedOut.size(); i++) {
       std::cout <<  checkedOut.at(i)->GetTitle() << std::endl;
    }
}
void Standard::addFavorite(Book* b) {
    favorites.push_back(b);
}
void Standard::removeFavorite(Book* b) {
    int idx = 0;
    for(unsigned i = 0; i < favorites.size(); i++) {
        if(favorites.at(i)->GetID() == b->GetID())
            idx = i;
    }
    favorites.erase(favorites.begin() + idx - 1); 
}
