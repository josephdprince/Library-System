#ifndef __LISTS_TEST_HPP__
#define __LISTS_TEST_HPP__

#include "Lists.hpp"
#include "gtest/gtest.h"
using namespace std;

TEST(ListsTest, EmptyList) {
  Composition temp;

  temp.SetName("Empty");

  string test = "";
  test = temp.print(0, 0);

  EXPECT_EQ(test, "Empty:\n\n");
}

TEST(ListsTest, OnlyBooks) {
  Composition temp;

  temp.SetName("Test");

  Individual temp2;
  temp2.SetBook(new Book("1984", "George Orwell", "dystopian", 1, 3.9, 1));

  Individual temp3;
  temp3.SetBook(new Book("A Confederacy of Dunces", "John Kennedy Toole",
                         "comedy", 2, 3.4, 1));

  temp.Add(&temp2);
  temp.Add(&temp3);

  string test = "";
  test = temp.print(0, 0);

  EXPECT_EQ(test, "Test:\n    - 1984\n    - A Confederacy of Dunces\n\n");

  delete temp2.GetBook();
  delete temp3.GetBook();
}

TEST(ListTest, OnlyListofList) {
  Composition Temp1;
  Composition Temp2;

  Temp1.SetName("Test");
  Temp2.SetName("Composition");

  Individual temp2;
  temp2.SetBook(new Book("1984", "George Orwell", "dystopian", 1, 3.9, 1));

  Individual temp3;
  temp3.SetBook(new Book("A Confederacy of Dunces", "John Kennedy Toole",
                         "comedy", 2, 3.4, 1));

  Temp2.Add(&temp2);
  Temp2.Add(&temp3);

  Temp1.Add(&Temp2);

  string test = "";
  test = Temp1.print(0, 0);

  EXPECT_EQ(test, "Test:\n    Composition:\n        - 1984\n        - A "
                  "Confederacy of Dunces\n\n");

  delete temp2.GetBook();
  delete temp3.GetBook();
}

TEST(ListTest, ListofList) {
  Composition Temp1;
  Composition Temp2;

  Temp1.SetName("Test");
  Temp2.SetName("Composition");

  Individual temp2;
  temp2.SetBook(new Book("1984", "George Orwell", "dystopian", 1, 3.9, 1));

  Individual temp3;
  temp3.SetBook(new Book("A Confederacy of Dunces", "John Kennedy Toole",
                         "comedy", 2, 3.4, 1));

  Individual temp4;
  temp4.SetBook(new Book("A Game of Thrones", "George R. R. Martin",
                         "political/fantasy", 3, 4.3, 1));

  Individual temp5;
  temp5.SetBook(
      new Book("The Color Purple", "Alice Walker", "fiction", 26, 2.1, 1));

  Temp2.Add(&temp2);
  Temp2.Add(&temp3);

  Temp1.Add(&temp4);
  Temp1.Add(&Temp2);
  Temp1.Add(&temp5);

  string test = "";
  test = Temp1.print(0, 0);

  EXPECT_EQ(
      test,
      "Test:\n    - A Game of Thrones\n    Composition:\n        - 1984\n      "
      "  - A Confederacy of Dunces\n    - The Color Purple\n\n");

  delete temp2.GetBook();
  delete temp3.GetBook();
  delete temp4.GetBook();
  delete temp5.GetBook();
}

#endif
