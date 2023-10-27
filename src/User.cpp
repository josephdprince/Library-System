#include <Library.h>

#include <string>

bool User::check(const std::string &uname, const std::string &pass) const {
  if (uname == "")
    return false;
  return userID == uname && password == pass;
}
