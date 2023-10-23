#ifndef __ADMIN_HPP__
#define __ADMIN_HPP__

#include "Library.hpp"
#include "Standard.hpp"
#include <string>
#include <vector>

class Admin : public Standard {
public:
  virtual void addBook(Book *, std::vector<Book *> &);
  Admin(const std::string &uname, const std::string &pass);
  inline std::string getUserType() { return "admin"; }
  virtual void remBook(Book *, std::vector<Book *> &);
};

#endif
