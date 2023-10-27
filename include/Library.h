#pragma once

#include "Book.h"
#include "Db.h"
#include "User.h"

#include <fstream>
#include <string>
#include <vector>

class Library {
private:
  Db *db;
  std::vector<User *> userList;
  User *currUser;
  void printMenu();

public:
  Library(Db *db);
  ~Library();
  void DisplayGenre();
  void DisplayGenre(std::string &genre);
  void DisplayPopular();
  void DisplayAll();
  bool Checkout(int);
  bool Return(int);
  void Recommend();
  bool AddBook(int);
  bool RemoveBook(int);
  void InsertLibrary(Book *);
  void View();
  Book *FindBook(int);
  void StoreLibrary();
  bool loadUsers();
  void createNewUser(int);
  void start();
  void CreateList();
  void ViewLists();
  bool PopulateUser();
  void CreateFile();
  void login();
  User *getUser(const std::string &, const std::string &, int);
  std::string GetCurrentUsername();

private:
  Composition *CreateList(std::ifstream &, bool);
};
