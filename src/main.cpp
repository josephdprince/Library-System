#include "../include/Db.h"
#include "../include/Library.h"

#include <iostream>

int main() {
  std::string connStr =
      "mongodb+srv://libuser:libuser@libsystem.igbknrs.mongodb.net/"
      "?retryWrites=true&w=majority";

  Db *db = new Db(connStr);
  Library *lib = new Library();

  lib->login();
  lib->start();
  lib->StoreLibrary();

  delete lib;
  return 0;
}