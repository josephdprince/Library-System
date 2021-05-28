#ifndef __LIBRARY_H__
#define __LIBRARY_H__

#include <vector>
#include <string>
#include "User.hpp"
#include "Book.hpp"

class Library {
    private:
	std::vector<Book*> library;
        std::vector<User*> userList;
        const User* currUser;
	void printMenu();
    public:
	Library();
	~Library();
	void DisplayGenre(std::string);
	void DisplayAll();
	void Checkout();
	void Return();
	void Recommend();
	void AddBook();
	void RemoveBook();
	void InsertLibrary(Book*);
	Book* FindBook(int);
	bool loadBooks();
        bool loadUsers();
	void start();
	void login();
	const User* getUser(const std::string&, const std::string&) const;
};
#endif
