#include <Db.h>
#include <Library.h>

#include <iostream>

int main() {
  // Put your connection string here
  std::string connStr = "";

  Db *db = new Db(connStr);
  Library *lib = new Library(db);

  if (!lib->loadUsers()) {
    std::cerr << "ERROR: Cannot load users from login.csv" << std::endl;
    exit(1);
  }

  lib->login();
  lib->start();

  delete db;
  delete lib;
  return 0;
}