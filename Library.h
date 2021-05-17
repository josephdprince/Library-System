#ifndef __LIBRARY_H__
#define __LIBRARY_H__

#include <vector>
#include "Book.h"

class Library {
    private:
	std::vector<Book*> library;
    public:
	void DisplayGenre(std::string);
	void DisplayAll();
	void Checkout(Book*);
	void InsertLibrary(Book*);
	Book* FindBook(int);
	void start();
	void login();
};
#endif
