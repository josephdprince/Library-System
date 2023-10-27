#pragma once

#include "Library.h"
#include "Lists.h"
#include "User.h"

#include <map>
#include <string>
#include <vector>

class Standard : public User {
private:
  std::vector<Book *> checkedOut;
  std::map<Book *, double> history;
  std::vector<Composition *> lists;

public:
  virtual ~Standard();
  virtual void newList(Library *);
  virtual void viewLists();
  void recommend(Library *lib);
  inline Standard(const std::string &uname, const std::string &pass) {
    userID = uname;
    password = pass;
  }
  virtual void AddCheckedOut(Book *);
  virtual void AddHistory(std::pair<Book *, double>);
  virtual void AddLists(Composition *);
  virtual void SetLists(std::vector<Composition *> lists) {
    this->lists = lists;
  }
  virtual std::vector<Book *> GetCheckedOut() { return checkedOut; }
  virtual std::map<Book *, double> GetHistory() { return history; }
  virtual std::vector<Composition *> GetLists() { return lists; }
  inline std::string getUserType() { return "standard"; }
  virtual void checkoutBook(Book *);
  virtual void returnBook(Book *, int);
  virtual void addBook(Book *, std::vector<Book *> &){};
  virtual void remBook(Book *, std::vector<Book *> &){};
  inline void displayBooks();
};