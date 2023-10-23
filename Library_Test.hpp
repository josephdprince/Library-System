#ifndef __LIBRARY_TEST_HPP__
#define __LIBRARY_TEST_HPP__

#include <iostream>
#include <string>

#include "Library.hpp"
#include "gtest/gtest.h"

using namespace std;

TEST(LibraryTest, FindBook) {
  Library *lib = new Library();

  if (!lib->loadUsers()) {
    cerr << "ERROR: Cannot load users from login.csv" << endl;
    exit(1);
  }

  if (!lib->loadBooks()) {
    cerr << "ERROR: Cannot load books from booklists.csv" << endl;
    exit(1);
  }

  Book *testBook = lib->FindBook(2);

  EXPECT_EQ(testBook->GetTitle(), "A Confederacy of Dunces");
}

TEST(LibraryTest, LoadBooks) {
  Library *lib = new Library();
  string result = "";

  if (lib->loadBooks()) {
    result = "success";
  } else {
    result = "failure";
  }

  EXPECT_EQ(result, "success");
}

TEST(LibraryTest, LoadUsers) {
  Library *lib = new Library();
  string result = "";

  if (lib->loadUsers()) {
    result = "success";
  } else {
    result = "failure";
  }

  EXPECT_EQ(result, "success");
}

TEST(LibraryTest, CreateNewUser) {
  Library *lib = new Library();

  lib->createNewUser(1);

  EXPECT_EQ(lib->GetCurrentUsername(), "testUsername");
}

TEST(LibraryTest, Checkout) {
  Library *lib = new Library();
  std::string result = "";

  if (lib->Checkout(1)) {
    result = "success";
  } else {
    result = "fail";
  }

  EXPECT_EQ(result, "fail");
}

TEST(LibraryTest, Return) {
  Library *lib = new Library();
  std::string result = "";

  if (lib->Return(1)) {
    result = "success";
  } else {
    result = "fail";
  }

  EXPECT_EQ(result, "fail");
}

TEST(LibraryTest, AddExistingBook) {
  Library *lib = new Library();
  std::string result = "";

  if (!lib->loadBooks()) {
    std::cerr << "ERROR: Cannot load books from booklists.csv" << std::endl;
    exit(1);
  }

  if (lib->AddBook(1)) {
    result = "success";
  } else {
    result = "fail";
  }
  EXPECT_EQ(result, "fail");
}

TEST(LibraryTest, AddNewBook) {
  Library *lib = new Library();
  std::string result = "";

  if (!lib->loadBooks()) {
    std::cerr << "ERROR: Cannot load books from booklists.csv" << std::endl;
    exit(1);
  }

  if (lib->AddBook(2)) {
    result = "success";
  } else {
    result = "fail";
  }
  EXPECT_EQ(result, "success");
}

TEST(LibraryTest, RemoveBook) {
  Library *lib = new Library();
  std::string result = "";

  if (!lib->loadBooks()) {
    std::cerr << "ERROR: Cannot load books from booklists.csv" << std::endl;
    exit(1);
  }

  if (lib->RemoveBook(1)) {
    result = "success";
  } else {
    result = "fail";
  }
  EXPECT_EQ(result, "fail");
}

#endif
