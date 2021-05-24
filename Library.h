#ifndef __LIBRARY_H__
#define __LIBRARY_H__

#include <vector>
#include <string>
#include "User.hpp"
#include "Book.h"

class Library {
    private:
	std::vector<Book*> library;
        std::vector<User*> userList;
        const User* currUser;
    public:
	Library();
	~Library();
	void DisplayGenre(std::string);
	void DisplayAll();
	void Checkout(Book*);
	void InsertLibrary(Book*);
	Book* FindBook(int);
        bool loadUsers();
	void start();
	void login();
	const User* getUser(const std::string&, const std::string&) const;
};
#endif
