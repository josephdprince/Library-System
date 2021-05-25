#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>
#include "Admin.hpp"
#include "Standard.cpp"
#include "Library.hpp"
using namespace std;

Library::Library() {
	currUser = nullptr;
}

Library::~Library() {
	delete currUser;
	currUser == nullptr;
	for(unsigned i = 0; i < userList.size(); i++) {
		delete userList.at(i);
		userList.at(i) = nullptr;
	}
	for(unsigned i = 0; i < library.size(); i++) {
		delete library.at(i);
		library.at(i) = nullptr;
	}
}

void Library::DisplayGenre(string genre) {
	for (int i = 0; i < library.size(); i++) {
		if (library.at(i)->GetGenre() == genre) {
			cout << library.at(i)->GetTitle() << " by " << library.at(i)->GetAuthor();
		}
	}
}

void Library::DisplayAll() {
	cout << setw(20) << "Genre" << setw(50) << "Title" << setw(35) << "Author" << setw(7) << "ID" << endl;
	cout << "----------------------------------------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < library.size(); i++) {
		cout << setw(20) << library.at(i)->GetGenre() <<  setw(50) << library.at(i)->GetTitle()
		     << setw(35) << library.at(i)->GetAuthor() << setw(7) << library.at(i)->GetID() << endl;
	}
}

bool Library::loadUsers() {
	ifstream fin;
	fin.open("login.csv");
	if(fin.fail()) {
		return false;
	}
	
	string name;
	string pass;
	string admin;
	fin >> name;

	while(!fin.eof()) {
		fin >> pass;
		fin >> admin;
		if(admin == "1") {
			User* tmp = new Admin(name, pass);
			userList.push_back(tmp);
		} else {
			User* tmp = new Standard(name, pass);
			userList.push_back(tmp);
		}
		fin >> name;
	}
	fin.close();

	return true;
}

void Library::login() {
	string nameInput;
	string passInput;
	cout << "Please enter your username: ";
	cin >> nameInput;
	cout << "Please enter your password: ";
	cin >> passInput;

	currUser = getUser(nameInput, passInput);
	if(currUser == nullptr) {
		cout << "Invalid username or password." << endl;
	} else {
		cout << "Welcome " << nameInput << "!" << endl;
		return;
	} 
}

void Library::printMenu() {
	cout << "Menu" << endl;
        cout << "- Display Library ('d')" << endl;
        cout << "- Check out Book ('c')" << endl;
        cout << "- Return Book ('r')" << endl;
	cout << "- Recommend Books ('m')" << endl;
        cout << "- Quit ('q')" << endl;
        cout << "Choose an action: " << endl;
}

void Library::start() {
	if(currUser == nullptr)
        	return;
        
    	char input;
	printMenu();
	bool isAdmin = false;
	if(currUser->getUserType() == "admin") {
		isAdmin = true;
		cout << "- Add Book to Library ('a')" << endl;
		cout << "- Remove Book from Library ('v')" << endl;
	}

    	cin >> input;
    	while (input != 'q') {
        	if (input == 'd')
            		DisplayAll();
        	else if (input == 'c')
			Checkout();
        	else if (input == 'r')
            		Return();
		else if (input == 'm')
			Recommend();
		else if (input == 'a' && isAdmin)
			AddBook();
		else if (input 'v' && isAdmin)
			RemoveBook();
        
        	cout << endl;
		printMenu();
        	cin >> input;
        	if(input != 'q')
        	    cout << endl;
    	}	
    	currUser = nullptr;
    	cout << "Bye!" << endl;
}

void Library::Checkout() {
	int bookID = 0;
	cout << "Enter ID of book to check out: ";
	cin >> bookID;
	Book* b = FindBook(bookID);
	currUser->checkoutBook(b, this);
}

void Library::Return() {
	int bookID = 0;
        cout << "Enter ID of book to return: ";
        cin >> bookID;
        Book* b = FindBook(bookID);
        currUser->returnBook(b, this);
}

void Library::Recommend() {
	currUser->recommend();
}

void Library::AddBook() {
	string title = "";
	string author = "";
	string genre = "";
	int ID = 0;
	cout << "Enter book title: ";
	getline(cin, title);
	cout << endl;
	cout << "Enter book author: ";
	getline(cin, author);
	cout << endl;
	cout << "Enter book genre: ";
	cin >> genre;
	cout << endl;
	cout << "Enter book ID: ";
	cin >> ID;
	Book* tmp = new Book(title, author, genre, ID);
	currUser->addBook(tmp, this);	
}

void Library::RemoveBook() {
	int bookID = 0;
	cout << "Enter ID of book to remove: ";
	cin >> bookID;
	Book* tmp = FindBook(bookID);
	currUser->remBook(tmp, this);
}

const User* Library::getUser(const string& name, const string& pw) const {
	for(unsigned i = 0; i < userList.size(); i++) {
		if(userList.at(i)->check(name, pw))
			return userList.at(i);
	}
	return nullptr;
}
