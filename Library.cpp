#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>
#include "Admin.hpp"
#include "Standard.cpp"
#include "Library.h"
using namespace std;

Library::Library() {
	currUser = nullptr;
}

Library::~Library() {
	delete currUser;
	currUser == nullptr;
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

	while(name != "end") {
		fin >> pass;
		fin >> admin;
		if(admin == "1") {
			Admin* tmp = new Admin(name, pass);
			userList.push_back(tmp);
		} else {
			Standard* tmp = new Standard(name, pass);
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
		cout << "Welcome " << nameInput << endl;
		return;
	} 
}

const User* Library::getUser(const string& name, const string& pw) const {
	for(unsigned i = 0; i < userList.size(); i++) {
		if(userList.at(i)->check(name, pw))
			return userList.at(i);
	}
	return nullptr;
}
