#pragma once

#include "Book.h"
#include "Composition.h"

#include <map>
#include <string>
#include <vector>
class Library;

class User {
protected:
  std::string userID;
  std::string password;

public:
  virtual ~User() {}
  virtual void viewLists() = 0;
  virtual void checkoutBook(Book *) = 0;
  virtual void returnBook(Book *, int) = 0;
  virtual void recommend(Library *lib) = 0;
  virtual void addBook(Book *, std::vector<Book *> &) = 0;
  virtual void remBook(Book *, std::vector<Book *> &) = 0;
  virtual void AddCheckedOut(Book *) = 0;
  virtual void AddHistory(std::pair<Book *, double>) = 0;
  virtual void AddLists(Composition *) = 0;
  virtual void AddExtraDel(Lists *) = 0;
  virtual void SetLists(std::vector<Composition *>) = 0;
  virtual void newList(Library *) = 0;
  virtual std::vector<Book *> GetCheckedOut() = 0;
  virtual std::map<Book *, double> GetHistory() = 0;
  virtual std::vector<Composition *> GetLists() = 0;
  inline std::string getUserID() { return userID; }
  virtual std::string getUserType() = 0;
  bool check(const std::string &uname, const std::string &pass) const;
};