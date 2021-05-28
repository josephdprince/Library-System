#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "Admin.hpp"
#include "Library.hpp"
using namespace std;

std::vector<Book*> Library::GetLibrary() {return library;}
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

Book* Library::FindBook(int id) {
	for (auto i : library) {
		if (i->GetID() == id) {
			return i;
		}
	}
}

bool Library::loadBooks() {
	ifstream fin;
	fin.open("booklists.csv");
	if(fin.fail())
		return false;
	
	string title = "";
	string author = "";
	string genre = "";
	string ID = "";
	string rating = "";
	string review = "";	
	
	while(!fin.eof()) {
		getline(fin, title, ',');
		getline(fin, author, ',');
		getline(fin, genre, ',');
		getline(fin, ID, ',');
		getline(fin, rating, ',');
		getline(fin, review, ',');
		
		string tmp1 = "";
		getline(fin, tmp1, '\n');
		
		int bookID = 0;
		double bookRate = 0.0;
		int bookRev = 0;
		stringstream s1(ID);
		stringstream s2(rating);
		stringstream s3(review);
		s1 >> bookID;
		s2 >> bookRate;
		s3 >> bookRev;
		
		Book* tmp = new Book(title, author, genre, bookID, bookRate, bookRev);
		library.push_back(tmp);
	}

	fin.close();
	return true;
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
		cout << "Welcome " << nameInput << "!" << endl;
		return;
	} 
}

bool Library::PopulateUser() {
	ifstream fin;
	fin.open("UserFiles/" + currUser->getUserID() + ".txt");
	if (!fin.is_open()) {
		cout << "Error loading user" << endl;
		return false;
	}

	string inputLine;
	istringstream in;
	int input1;
	double input2;

	//Populate checked out books
	getline(fin, inputLine);
	while (inputLine != "$") {
		in.str(inputLine);
		while (in >> input1) {
			currUser->AddCheckedOut(FindBook(input1));
		}
		getline(fin, inputLine);
	}
	
	//Populate history map
	getline(fin, inputLine);
	while (inputLine != "$") {
		in.str(inputLine);
		while (in >> input1);
			in >> input2;
			pair<Book*, double> histVal;

			histVal.first = FindBook(input1);
			histVal.second = input2;

			currUser->AddHistory(histVal);
		getline(fin, inputLine);
	}
	
	//Populate book lists
	while (!fin.eof()) {
		currUser->AddLists(CreateList(fin));
	}

	fin.close();
}

Composition* Library::CreateList(ifstream& fin) {
	string list_name;
	string input;
	int tempID;
	istringstream in;

	getline(fin, list_name);

	Composition* temp = new Composition();
	temp->SetName(list_name);

	getline(fin, input);
	while (input != "}") {
		if (input == "/") {
			temp->Add(CreateList(fin));
		}
		else {
			in.str(input);
			in >> tempID;

			Individual* tempBook = new Individual();
			tempBook->SetBook(FindBook(tempID));

			temp->Add(tempBook);
		}
	}
	return temp;
}

void Library::printMenu() {
	cout << "Menu" << endl;
        cout << "- Display Library ('d')" << endl;
        cout << "- Check out Book ('c')" << endl;
        cout << "- Return Book ('r')" << endl;
	cout << "- Recommend Books ('m')" << endl;
        cout << "- Quit ('q')" << endl;
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
	cout << "Choose an action: " << endl;

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
		else if (input == 'v' && isAdmin)
			RemoveBook();
        
        	cout << endl;
		printMenu();
		if(currUser->getUserType() == "admin") {
                	isAdmin = true;
                	cout << "- Add Book to Library ('a')" << endl;
                	cout << "- Remove Book from Library ('v')" << endl;
       		}
        	cout << "Choose an action: " << endl;
        	cin >> input;
        	if(input != 'q')
        	    cout << endl;
    	}	
	CreateFile();
    	currUser = nullptr;
    	cout << "Bye!" << endl;
}

void Library::CreateFile() {
	ofstream fout; 
	fout.open("UserFiles/" + currUser->getUserID() + ".txt");

	for (auto i : currUser->GetCheckedOut()) {
		fout << i->GetID() << " ";
	}
	fout << "\n$\n";

	for (auto i : currUser->GetHistory()) {
		fout << i.first << " " << i.second << " ";
	}
	fout << "\n$\n";

	for (auto i : currUser->GetLists()) {
		i->file(fout);
	}
	fout.close();
}

void Library::Checkout() {
	int bookID = 0;
	cout << "Enter ID of book to check out: ";
	cin >> bookID;
	Book* b = FindBook(bookID);
	currUser->checkoutBook(b, library);
}

void Library::Return() {
	int bookID = 0;
        cout << "Enter ID of book to return: ";
        cin >> bookID;
        Book* b = FindBook(bookID);
        currUser->returnBook(b, library);
}

void Library::Recommend() {
	currUser->recommend(library);
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
	Book* tmp = new Book(title, author, genre, ID, 0.0, 0);
	currUser->addBook(tmp, library);	
}

void Library::RemoveBook() {
	int bookID = 0;
	cout << "Enter ID of book to remove: ";
	cin >> bookID;
	Book* tmp = FindBook(bookID);
	currUser->remBook(tmp, library);
}

User* Library::getUser(const string& name, const string& pw) {
	for(unsigned i = 0; i < userList.size(); i++) {
		if(userList.at(i)->check(name, pw))
			return userList.at(i);
	}
	return nullptr;
}
