#ifndef __LIBRARY_H__
#define __LIBRARY_H__

#include <vector>

class Library {
    private:
	vector<Book*> library
    public:
	void DisplayGenre(string);
	void DisplayAll();
	void Checkout(Book*)
	void InsertLibrary(Book*);
	Book* FindBook(int);
	void start();
	void login();
};
#endif
