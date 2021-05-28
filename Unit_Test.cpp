#include "gtest/gtest.h"
#include "Admin_Test.hpp"
#include "Book_Test.hpp"
#include "Library_Test.hpp"
#include "Lists_Test.hpp"
#include "Standard_Test.hpp"
#include "Strategy_Test.hpp"
#include "User_Test.hpp"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
