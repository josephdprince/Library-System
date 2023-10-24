#pragma once

#include "Book.h"
#include "Lists.h"

#include <fstream>
#include <string>

class Individual : public Lists {
private:
  Book *book;

public:
  virtual std::string print(int space, int key);
  virtual void file(std::ofstream &fout);
  virtual void find_rating();
  virtual std::string return_type();
  Book *GetBook();
  void SetBook(Book *book);
};