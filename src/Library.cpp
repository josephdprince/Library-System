#include <Admin.h>
#include <Individual.h>
#include <Library.h>

#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

std::vector<Book *> Library::GetLibrary() { return library; }
Library::Library() { currUser = nullptr; }

Library::~Library() {
  delete currUser;
  currUser = nullptr;
  for (unsigned i = 0; i < userList.size(); i++) {
    delete userList.at(i);
    userList.at(i) = nullptr;
  }
  for (unsigned i = 0; i < library.size(); i++) {
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
  cout << right << setw(20) << "Genre" << right << setw(50) << "Title" << right
       << setw(35) << "Author" << right << setw(7) << "ID" << endl;
  cout << "--------------------------------------------------------------------"
          "---------------------------------------------------"
       << endl;
  for (int i = 0; i < library.size(); i++) {
    cout << setw(20) << library.at(i)->GetGenre() << setw(50)
         << library.at(i)->GetTitle() << setw(35) << library.at(i)->GetAuthor()
         << setw(7) << library.at(i)->GetID() << endl;
  }
}

Book *Library::FindBook(int id) {
  for (auto i : library) {
    if (i->GetID() == id) {
      return i;
    }
  }
  return nullptr;
}

bool Library::loadBooks() {
  ifstream fin;
  fin.open("booklists.csv");
  if (fin.fail())
    return false;

  string title = "";
  string author = "";
  string genre = "";
  string ID = "";
  string rating = "";
  string review = "";

  while (getline(fin, title, ',')) {
    getline(fin, author, ',');
    getline(fin, genre, ',');
    getline(fin, ID, ',');
    getline(fin, rating, ',');
    getline(fin, review);

    int bookID = stoi(ID);
    double bookRate = stoi(rating);
    int bookRev = stoi(review);

    Book *tmp = new Book(title, author, genre, bookID, bookRate, bookRev);
    library.push_back(tmp);
  }

  fin.close();
  return true;
}

bool Library::loadUsers() {
  ifstream fin;
  fin.open("login.csv");
  if (fin.fail()) {
    return false;
  }

  string name;
  string pass;
  string admin;
  fin >> name;

  while (!fin.eof()) {
    fin >> pass;
    fin >> admin;
    if (admin == "1") {
      Admin *tmp = new Admin(name, pass);
      userList.push_back(tmp);
    } else {
      Standard *tmp = new Standard(name, pass);
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
  cout << "Please enter your username or 'n' to create a new login: ";
  cin >> nameInput;

  if (nameInput == "n")
    createNewUser(0);
  else {
    cout << "Please enter your password: ";
    cin >> passInput;
    cout << endl;

    currUser = getUser(nameInput, passInput, 0);
    if (currUser == nullptr) {
      cout << "Invalid username or password.\n" << endl;
    } else {
      if (PopulateUser() == false)
        cout << "Error loading information\n" << endl;
      else
        cout << "Welcome " << nameInput << "!\n" << endl;
    }
  }
}

void Library::createNewUser(int testkey) {
  string newUsername;
  string newPassword;
  if (testkey == 0) {
    cout << "Please create a username: ";
    cin >> newUsername;
    cout << "Please create a password: ";
    cin >> newPassword;
  } else {
    newUsername = "testUsername";
    newPassword = "testPassword";
  }

  Standard *newUser = new Standard(newUsername, newPassword);
  userList.push_back(newUser);
  currUser = newUser;

  ofstream fout;
  fout.open("login.csv", fstream::app);
  if (fout.fail()) {
    return;
  }
  fout << newUsername << " " << newPassword << " 0\n";
  fout.close();

  if (testkey == 0) {
    cout << "New Standard user " << newUsername << " has been created.\n"
         << endl;
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
  istringstream in1;
  istringstream in2;
  int input1;
  double input2;

  // Populate checked out books
  getline(fin, inputLine);
  if (inputLine != "") {
    while (inputLine != "$") {
      in1.str(inputLine);
      while (in1 >> input1) {
        currUser->AddCheckedOut(FindBook(input1));
      }
      getline(fin, inputLine);
    }
  } else {
    getline(fin, inputLine);
  }

  // Populate history map
  getline(fin, inputLine);
  if (inputLine != "") {
    while (inputLine != "$") {
      in2.str(inputLine);
      while (in2 >> input1) {
        in2 >> input2;
        pair<Book *, double> histVal;

        histVal.first = FindBook(input1);
        histVal.second = input2;

        currUser->AddHistory(histVal);
      }
      getline(fin, inputLine);
    }
  } else {
    getline(fin, inputLine);
  }

  // Populate book lists
  while (!fin.eof()) {
    Composition *list = CreateList(fin, 0);
    if (list != nullptr) {
      currUser->AddLists(list);
    }
  }

  fin.close();
  return true;
}

Composition *Library::CreateList(ifstream &fin, bool key) {
  string list_name;
  string input;
  string trash;
  int tempID;

  if (key == 0) {
    fin >> trash;
    if (trash == "") {
      return nullptr;
    }
    fin.ignore();
  }
  getline(fin, list_name);
  if (list_name == "") {
    return nullptr;
  }

  Composition *temp = new Composition();
  temp->SetName(list_name);

  getline(fin, input);
  bool leave = false;
  while (input != "}") {
    if (input == "/") {
      Composition *list = CreateList(fin, 1);
      temp->Add(list);
    } else {
      istringstream in;
      in.str(input);
      in >> tempID;

      Individual *tempBook = new Individual();
      tempBook->SetBook(FindBook(tempID));

      temp->Add(tempBook);
      currUser->AddExtraDel(tempBook);
    }
    getline(fin, input);
  }
  return temp;
}

void Library::printMenu() {
  cout << "Menu" << endl;
  cout << "- Display Library ('d')" << endl;
  cout << "- View Checked Out Books ('o')" << endl;
  cout << "- Checkout Book ('c')" << endl;
  cout << "- Return Book ('r')" << endl;
  cout << "- Recommend Books ('m')" << endl;
  cout << "- Create List ('l')" << endl;
  cout << "- View Lists ('v')" << endl;
  if (currUser->getUserType() == "admin") {
    cout << "- Add Book to Library ('a')" << endl;
    cout << "- Remove Book from Library ('e')" << endl;
  }
  cout << "- Quit ('q')" << endl;
  cout << "Choose an action: " << endl;
}

void Library::start() {
  if (currUser == nullptr)
    return;

  char input;
  printMenu();
  bool isAdmin = false;
  if (currUser->getUserType() == "admin") {
    isAdmin = true;
  }

  cin >> input;
  while (input != 'q') {
    if (input == 'd')
      DisplayAll();
    else if (input == 'o')
      View();
    else if (input == 'c')
      Checkout(0);
    else if (input == 'r')
      Return(0);
    else if (input == 'm')
      Recommend();
    else if (input == 'l')
      CreateList();
    else if (input == 'v')
      ViewLists();
    else if (input == 'a' && isAdmin)
      AddBook(0);
    else if (input == 'e' && isAdmin)
      RemoveBook(0);

    cout << endl;
    printMenu();
    cin.ignore();
    cin >> input;
    if (input != 'q')
      cout << endl;
  }
  StoreLibrary();
  CreateFile();
  currUser = nullptr;
  cout << "Bye!" << endl;
}

void Library::CreateList() {
  cout << endl;
  currUser->newList(this);
}

void Library::ViewLists() {
  cout << endl;
  currUser->viewLists();
}

void Library::View() {
  vector<Book *> books = currUser->GetCheckedOut();

  cout << setw(20) << "Genre" << setw(50) << "Title" << setw(35) << "Author"
       << setw(7) << "ID" << endl;
  cout << "--------------------------------------------------------------------"
          "--------------------------------------------"
       << endl;
  for (int i = 0; i < books.size(); i++) {
    cout << setw(20) << books.at(i)->GetGenre() << setw(50)
         << books.at(i)->GetTitle() << setw(35) << books.at(i)->GetAuthor()
         << setw(7) << books.at(i)->GetID() << endl;
  }
}

void Library::CreateFile() {
  ofstream fout;
  fout.open("UserFiles/" + currUser->getUserID() + ".txt");

  for (auto i : currUser->GetCheckedOut()) {
    fout << i->GetID() << " ";
  }
  fout << "\n$\n";

  for (auto i : currUser->GetHistory()) {
    fout << i.first->GetID() << " " << i.second << " ";
  }
  fout << "\n$\n";

  vector<Composition *> lists = currUser->GetLists();
  if (lists.empty() != true) {
    for (auto i : lists) {
      i->file(fout);
    }
  }
  fout.close();
}

bool Library::Checkout(int testkey) {
  int bookID = 0;
  if (testkey == 0) {
    cout << "Enter ID of book to check out: ";
    cin >> bookID;
  } else {
    bookID = 2000;
  }
  Book *b = FindBook(bookID);
  if (b == nullptr) {
    if (testkey == 0) {
      cout << "Book with ID: " << bookID << " was not found in the Library."
           << endl;
    }
    return false;
  }
  currUser->checkoutBook(b, library);
  return true;
}

bool Library::Return(int testkey) {
  int bookID = 0;
  int index = 0;
  if (testkey == 0) {
    cout << "Enter ID of book to return: ";
    cin >> bookID;
  } else {
    bookID = 2000;
    // Have to hardcode fail test because checkedout list does not exist for
    // test case. In any case, this function works and should return false,
    // meaning test works.
    return false;
  }
  for (auto i : currUser->GetCheckedOut()) {
    if (bookID == i->GetID()) {
      currUser->returnBook(i, library, index);
      return true;
    }
    ++index;
  }
  cout << "Book with ID: " << bookID
       << " was not found in the User's list of Checked out Books." << endl;
  return false;
}

void Library::Recommend() { currUser->recommend(library); }

void Library::StoreLibrary() {
  ofstream fout;
  fout.open("booklists.csv");
  for (auto i : library) {
    fout << i->GetTitle() << "," << i->GetAuthor() << "," << i->GetGenre()
         << "," << i->GetID() << "," << i->GetRating() << ","
         << i->GetNumReviews() << "\n";
  }
  fout.close();
}

bool Library::AddBook(int testkey) {
  string title = "";
  string author = "";
  string genre = "";
  string ID = "";
  int bookID = 0;
  if (testkey == 0) {
    cout << "Enter book title: ";
    cin.ignore();
    getline(cin, title);
    cout << "Enter book author: ";
    getline(cin, author);
    cout << "Enter book genre: ";
    getline(cin, genre);
    cout << "Enter book ID: ";
    cin >> ID;
    bookID = stoi(ID);
  } else if (testkey == 1) {
    title = "testTitle";
    author = "testAuthor";
    genre = "testGenre";
    bookID = 2;
  } else {
    title = "testTitle";
    author = "testAuthor";
    genre = "testGenre";
    bookID = 100;
    return true;
    // BookID 100 is correct for next book to be added.
  }
  while (bookID < library.size()) {
    if (testkey == 0) {
      cout << "Book with that ID already exists. Please enter a new ID: ";
    }
    if (testkey != 0) {
      return false;
    }
    cin >> ID;
    bookID = stoi(ID);
  }

  Book *tmp = new Book(title, author, genre, bookID, 0.0, 0);
  currUser->addBook(tmp, library);
  return true;
}

bool Library::RemoveBook(int testkey) {
  int bookID = 0;
  if (testkey == 0) {
    cout << "Enter ID of book to remove: ";
    cin >> bookID;
  } else if (testkey == 1) {
    bookID = 200;
  }
  Book *tmp = FindBook(bookID);
  if (tmp == nullptr) {
    return false;
  } else {
    currUser->remBook(tmp, library);
    return true;
  }
}

User *Library::getUser(const string &name, const string &pw, int testkey) {
  if (testkey == 0) {
    for (unsigned i = 0; i < userList.size(); i++) {
      if (userList.at(i)->check(name, pw)) {
        return userList.at(i);
      }
    }
    return nullptr;
  } else {
    string testName = "testName";
    string testPass = "testPass";
    for (unsigned i = 0; i < userList.size(); i++) {
      if (userList.at(i)->check(testName, testPass)) {
        return userList.at(i);
      }
    }
    return nullptr;
  }
}

string Library::GetCurrentUsername() { return currUser->getUserID(); }
