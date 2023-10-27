#pragma once

#include "Book.h"
#include "Library.h"

#include <map>
#include <vector>

class Strategy {
public:
  virtual std::string recommendation_algorithm(std::map<Book *, double>,
                                               Library *lib, bool) = 0;
};

class Favorites : public Strategy {
public:
  std::string str = "";
  virtual std::string recommendation_algorithm(std::map<Book *, double> list,
                                               Library *lib, bool key);
};

class Popular : public Strategy {
public:
  std::string str = "";
  virtual std::string recommendation_algorithm(std::map<Book *, double> list,
                                               Library *lib, bool key);
};