#include "../include/Db.h"
#include "../include/Library.h"

#include <iostream>

int main() {
  const std::string connStr =
      "mongodb+srv://libuser:libuser@libsystem.igbknrs.mongodb.net/"
      "?retryWrites=true&w=majority";
  Db *db = new Db(connStr);
  Library *lib = new Library();
  if (!lib->loadUsers()) {
    std::cerr << "ERROR: Cannot load users from login.csv" << std::endl;
    exit(1);
  }

  if (!lib->loadBooks()) {
    std::cerr << "ERROR: Cannot load books from booklists.csv" << std::endl;
    exit(1);
  }

  lib->login();
  lib->start();
  lib->StoreLibrary();

  delete lib;
  return 0;
}