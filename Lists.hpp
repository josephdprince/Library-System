#ifndef __RATINGS_HPP__
#define __RATINGS_HPP__

#include "Book.hpp"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

class Lists {
public:
  virtual std::string print(int, int) = 0;
  virtual void file(std::ofstream &) = 0;
  virtual void find_rating() = 0;
  virtual std::string return_type() = 0;
};

class Individual : public Lists {
private:
  Book *book;

public:
  virtual std::string print(int space, int key) {
    std::string str = "";
    for (int i = 0; i < space; ++i) {
      std::cout << "    ";
      str += "    ";
    }
    std::cout << "- " << book->GetTitle() << " by " << book->GetAuthor()
              << std::endl;
    str += "- " + book->GetTitle() + "\n";
    return str;
  }

  virtual void file(std::ofstream &fout) { fout << book->GetID() << std::endl; }

  virtual void find_rating() {
    std::cout << book->GetTitle() << " is rated " << book->GetRating() << "/5.0"
              << std::endl;
  }

  void SetBook(Book *book) { this->book = book; }

  Book *GetBook() { return book; }

  virtual std::string return_type() { return "Individual"; }
};

class Composition : public Lists {
private:
  std::string list_name;
  std::vector<Lists *> list;

public:
  virtual std::string print(int space, int key) {
    std::string str = "";
    for (int i = 0; i < space; ++i) {
      std::cout << "    ";
      str += "    ";
    }
    std::cout << list_name << ":" << std::endl;
    str += list_name + ":\n";
    for (auto i : list) {
      str += i->print(space + 1, key);
    }
    if (space == 0 && key != 1) {
      std::cout << std::endl;
      str += "\n";
    }
    return str;
  }

  virtual void file(std::ofstream &fout) {
    fout << "/" << std::endl;
    fout << list_name << std::endl;
    for (auto i : list) {
      i->file(fout);
    }
    fout << "}" << std::endl;
  }

  virtual void find_rating() {
    for (auto i : list) {
      i->find_rating();
    }
  }

  void Add(Lists *obj) { list.push_back(obj); }

  std::vector<Lists *> GetList() { return list; }

  void SetName(std::string name) { list_name = name; }

  std::string GetName() { return list_name; }

  virtual std::string return_type() { return "Composition"; }
};

#endif
