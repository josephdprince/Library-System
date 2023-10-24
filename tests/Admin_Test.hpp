#pragma once

#include <iostream>
#include <string>

#include "../include/Admin.h"
#include "../include/Library.h"
#include "gtest/gtest.h"

using namespace std;

TEST(AdminTest, AssignedAdmin) {
  Admin *testAdmin = new Admin("userName", "passWord");
  string test = testAdmin->getUserType();

  // Tests if admin is properly assigned.

  EXPECT_EQ(test, "admin");
}

TEST(AdminTest, AddExistingBook) {
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

TEST(AdminTest, AddNewBook) {
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

TEST(AdminTest, RemoveBook) {
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
