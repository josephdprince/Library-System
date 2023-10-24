#pragma once

#include "../include/Strategy.h"
#include "gtest/gtest.h"
#include <map>
#include <string>
#include <vector>
using namespace std;

TEST(StrategyTest, PopularOnly) {
  Popular temp;
  map<Book *, double> mp;
  vector<Book *> list;

  Book *book1 = new Book("1984", "George Orwell", "dystopian", 1, 3.9, 1);
  list.push_back(book1);

  Book *book2 = new Book("A Confederacy of Dunces", "John Kennedy Toole",
                         "comedy", 2, 3.4, 1);
  list.push_back(book2);

  Book *book3 = new Book("A Game of Thrones", "George R. R. Martin",
                         "political/fantasy", 3, 4.3, 1);
  list.push_back(book3);

  string test = "";
  test = temp.recommendation_algorithm(mp, list, 1);

  EXPECT_EQ(test, "1984\nA Game of Thrones\n");

  for (auto i : list)
    delete i;
}

TEST(StrategyTest, LikedOnly) {
  Favorites temp;
  map<Book *, double> mp;
  vector<Book *> list;

  Book *book1 = new Book("1984", "George Orwell", "dystopian", 1, 3.4, 1);
  list.push_back(book1);

  Book *book2 = new Book("A Confederacy of Dunces", "John Kennedy Toole",
                         "comedy", 2, 3.4, 1);
  list.push_back(book2);

  Book *book3 = new Book("A Game of Thrones", "George R. R. Martin",
                         "political/fantasy", 3, 2.3, 1);
  list.push_back(book3);

  Book *book4 = new Book("The Giver", "Lois Lowry", "dystopian", 40, 2.3, 1);
  list.push_back(book4);

  Book *book5 = new Book("The Handmaid's Tale", "Margaret Atwood", "dystopian",
                         48, 2.3, 1);
  list.push_back(book5);

  pair<Book *, double> pr(book1, 4.2);
  mp.insert(pr);

  string test = "";
  test = temp.recommendation_algorithm(mp, list, 1);

  EXPECT_EQ(test, "The Giver\nThe Handmaid's Tale\n");

  for (auto i : list)
    delete i;
}

TEST(StrategyTest, PopularAndLiked) {
  Popular temp1;
  Favorites temp2;
  map<Book *, double> mp;
  vector<Book *> list;

  Book *book1 = new Book("1984", "George Orwell", "dystopian", 1, 3.4, 1);
  list.push_back(book1);

  Book *book2 = new Book("A Confederacy of Dunces", "John Kennedy Toole",
                         "comedy", 2, 3.4, 1);
  list.push_back(book2);

  Book *book3 = new Book("A Game of Thrones", "George R. R. Martin",
                         "political/fantasy", 3, 4.3, 1);
  list.push_back(book3);

  Book *book4 = new Book("The Giver", "Lois Lowry", "dystopian", 40, 2.3, 1);
  list.push_back(book4);

  Book *book5 = new Book("The Handmaid's Tale", "Margaret Atwood", "dystopian",
                         48, 2.3, 1);
  list.push_back(book5);

  pair<Book *, double> pr(book1, 4.2);
  mp.insert(pr);

  string alg1 = "";
  alg1 = temp1.recommendation_algorithm(mp, list, 1);

  string alg2 = "";
  alg2 = temp2.recommendation_algorithm(mp, list, 1);

  string test = alg1 + alg2;

  EXPECT_EQ(test, "A Game of Thrones\nThe Giver\nThe Handmaid's Tale\n");

  for (auto i : list)
    delete i;
}