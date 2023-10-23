#ifndef __STRATEGY_HPP__
#define __STRATEGY_HPP__
#include <iomanip>
#include <iostream>
#include <map>
#include <vector>

#include "Book.hpp"

class Strategy {
public:
  virtual std::string recommendation_algorithm(std::map<Book *, double>,
                                               std::vector<Book *> &, bool) = 0;
};
// This will go off of books user already likes
class Favorites : public Strategy {
public:
  std::string str = "";
  virtual std::string recommendation_algorithm(std::map<Book *, double> list,
                                               std::vector<Book *> &library,
                                               bool key) {
    std::vector<Book *> likedBooks;
    for (auto i : list) {
      if (i.second >= 4.0) {
        likedBooks.push_back(i.first);
      }
    }
    // We now havea vector of books that the user likes
    int index = 0;
    for (auto i : library) {
      for (auto j : likedBooks) {
        if (i->GetGenre() == j->GetGenre() && i->GetTitle() != j->GetTitle()) {
          if (key == 0) {
            std::cout << std::setw(20) << i->GetGenre() << std::setw(50)
                      << i->GetTitle() << std::setw(35) << i->GetAuthor()
                      << std::setw(7) << i->GetID() << std::endl;
          }

          str += i->GetTitle() + "\n";
          library.erase(library.begin() + index - 1);
        }
      }
      ++index;
    }
    return str;
  }
};

// this will go off of popular books in the library
class Popular : public Strategy {
public:
  std::string str = "";
  virtual std::string recommendation_algorithm(std::map<Book *, double> list,
                                               std::vector<Book *> &library,
                                               bool key) {
    for (auto i : library) {
      if (i->GetRating() > 3.5) {
        if (key == 0) {
          std::cout << std::setw(20) << i->GetGenre() << std::setw(50)
                    << i->GetTitle() << std::setw(35) << i->GetAuthor()
                    << std::setw(7) << i->GetID() << std::endl;
        }

        str += i->GetTitle() + "\n";
      }
    }
    return str;
  }
};

#endif
