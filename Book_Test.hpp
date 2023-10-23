#ifndef __BOOK_TEST_HPP__
#define __BOOK_TEST_HPP__

#include "Book.hpp"
#include "gtest/gtest.h"

TEST(BookTest, TitleGetter) {
  Book *testBook = new Book("title", "author", "genre", 222, 0, 0);

  // Tests the GetTitle() function

  EXPECT_EQ(testBook->GetTitle(), "title");

  delete testBook;
}

TEST(BookTest, AuthorGetter) {
  Book *testBook = new Book("title", "author", "genre", 222, 0, 0);

  // Tests the GetAuthor() function

  EXPECT_EQ(testBook->GetAuthor(), "author");

  delete testBook;
}

TEST(BookTest, GenreGetter) {
  Book *testBook = new Book("title", "author", "genre", 222, 0, 0);

  // Tests the GetGenre() function

  EXPECT_EQ(testBook->GetGenre(), "genre");

  delete testBook;
}

TEST(BookTest, IDGetter) {
  Book *testBook = new Book("title", "author", "genre", 222, 0, 0);

  // Tests the GetID() function

  EXPECT_EQ(testBook->GetID(), 222);

  delete testBook;
}

TEST(BookTest, RatingGetter) {
  Book *testBook = new Book("title", "author", "genre", 222, 0, 0);

  // Tests the GetRating() function

  EXPECT_EQ(testBook->GetRating(), 0);

  delete testBook;
}

TEST(BookTest, NumReviewGetter) {
  Book *testBook = new Book("title", "author", "genre", 222, 0, 0);

  // Tests the GetNumReviews() function

  EXPECT_EQ(testBook->GetNumReviews(), 0);

  delete testBook;
}

TEST(BookTest, TitleSetter) {
  Book *testBook = new Book("title", "author", "genre", 222, 0, 0);
  testBook->SetTitle("newTitle");

  // Tests the SetTitle() function

  EXPECT_EQ(testBook->GetTitle(), "newTitle");

  delete testBook;
}

TEST(BookTest, AuthorSetter) {
  Book *testBook = new Book("title", "author", "genre", 222, 0, 0);
  testBook->SetAuthor("newAuthor");

  // Tests the SetAuthor() function

  EXPECT_EQ(testBook->GetAuthor(), "newAuthor");

  delete testBook;
}

TEST(BookTest, GenreSetter) {
  Book *testBook = new Book("title", "author", "genre", 222, 0, 0);
  testBook->SetGenre("newGenre");

  // Tests the SetGenre() function

  EXPECT_EQ(testBook->GetGenre(), "newGenre");

  delete testBook;
}

TEST(BookTest, IDSetter) {
  Book *testBook = new Book("title", "author", "genre", 222, 0, 0);
  testBook->SetID(333);

  // Tests the SetID() function

  EXPECT_EQ(testBook->GetID(), 333);

  delete testBook;
}

TEST(BookTest, RatingSetter) {
  Book *testBook = new Book("title", "author", "genre", 222, 0, 0);
  testBook->SetRating(1);

  // Tests the SetRating() function

  EXPECT_EQ(testBook->GetRating(), 1);

  delete testBook;
}

TEST(BookTest, NumReviewsSetter) {
  Book *testBook = new Book("title", "author", "genre", 222, 0, 0);
  testBook->SetNumReviews(1);

  // Tests the SetNumReviews() function

  EXPECT_EQ(testBook->GetNumReviews(), 1);

  delete testBook;
}

#endif
