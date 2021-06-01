#ifndef __LIBRARY_HPP__
#define __LIBRARY_HPP__

#include <vector>
#include <string>
#include <fstream>
#include "User.hpp"
#include "Book.hpp"

class Library {
    private:
	std::vector<Book*> library;
        std::vector<User*> userList;
        User* currUser;
	void printMenu();
    public:
	Library();
	~Library();
	std::vector<Book*> GetLibrary();
	void DisplayGenre(std::string);
	void DisplayAll();
	bool Checkout(int);
	bool Return(int);
	void Recommend();
	bool AddBook(int);
	bool RemoveBook(int);
	void InsertLibrary(Book*);
	void View();
	Book* FindBook(int);
	void StoreLibrary();
	bool loadBooks();
        bool loadUsers();
	void createNewUser(int);
	void start();
	void CreateList();
	void ViewLists();
	bool PopulateUser();
	void CreateFile();
	void login();
	User* getUser(const std::string&, const std::string&, int);
	std::string GetCurrentUsername();
    private:
	Composition* CreateList(std::ifstream&, bool);
};
#endif
