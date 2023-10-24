#pragma once

#include "../include/Standard.h"
#include "gtest/gtest.h"

TEST(StandardTest, checkoutBook) {
  Library *lib = new Library();
  std::string result = "";

  if (lib->Checkout(1)) {
    result = "success";
  } else {
    result = "fail";
  }

  EXPECT_EQ(result, "fail");
}

TEST(StandardTest, returnBook) {
  Library *lib = new Library();
  std::string result = "";

  if (lib->Return(1)) {
    result = "success";
  } else {
    result = "fail";
  }

  EXPECT_EQ(result, "fail");
}
