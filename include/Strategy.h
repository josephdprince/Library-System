#pragma once

#include "Book.h"

#include <map>
#include <vector>

class Strategy {
public:
  virtual std::string recommendation_algorithm(std::map<Book *, double>,
                                               std::vector<Book *> &, bool) = 0;
};

class Favorites : public Strategy {
public:
  std::string str = "";
  virtual std::string recommendation_algorithm(std::map<Book *, double> list,
                                               std::vector<Book *> &library,
                                               bool key);
};

class Popular : public Strategy {
public:
  std::string str = "";
  virtual std::string recommendation_algorithm(std::map<Book *, double> list,
                                               std::vector<Book *> &library,
                                               bool key);
};