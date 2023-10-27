#include <Db.h>
#include <Library.h>

#include <iostream>

int main() {
  std::string connStr =
      "mongodb+srv://libuser:libuser@libsystem.igbknrs.mongodb.net/"
      "?retryWrites=true&w=majority";

  Db *db = new Db(connStr);
  Library *lib = new Library();

  db->LibDisplayAll();

  // lib->login();
  // lib->start();
  // lib->StoreLibrary();

  delete db;
  delete lib;
  return 0;
}