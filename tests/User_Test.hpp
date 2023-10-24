#pragma once

#include "../include/Library.h"
#include "../include/User.h"
#include "gtest/gtest.h"

#include <iostream>

TEST(UserTest, Check) {
  Library *lib = new Library();
  std::string result = "";
  User *testUser = nullptr;

  if (!lib->loadUsers()) {
    std::cerr << "ERROR: Cannot load users from login.csv" << std::endl;
    exit(1);
  }

  testUser = lib->getUser("testname", "testpass", 1);
  if (testUser == nullptr) {
    result = "fail";
  } else {
    result = "success";
  }

  EXPECT_EQ(result, "fail");
}
