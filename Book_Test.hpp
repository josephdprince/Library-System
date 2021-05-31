#ifndef __BOOK_TEST_HPP__
#define __BOOK_TEST_HPP__

#include "gtest/gtest.h"
#include "Book.hpp"

TEST(BookTest, TitleGetter) {
	Book* testBook = new Book("title", "author", "genre", 222, 0, 0);
	
	//Tests the GetTitle() function
	
	EXPECT_EQ(testBook->GetTitle(), "title");
}

TEST(BookTest, AuthorGetter) {
        Book* testBook = new Book("title", "author", "genre", 222, 0, 0);

        //Tests the GetAuthor() function

        EXPECT_EQ(testBook->GetAuthor(), "author");
}

TEST(BookTest, GenreGetter) {
        Book* testBook = new Book("title", "author", "genre", 222, 0, 0);

        //Tests the GetGenre() function

        EXPECT_EQ(testBook->GetGenre(), "genre");
}

TEST(BookTest, IDGetter) {
        Book* testBook = new Book("title", "author", "genre", 222, 0, 0);

        //Tests the GetID() function

        EXPECT_EQ(testBook->GetID(), 222);
}

TEST(BookTest, RatingGetter) {
        Book* testBook = new Book("title", "author", "genre", 222, 0, 0);

        //Tests the GetRating() function

        EXPECT_EQ(testBook->GetRating(), 0);
}

TEST(BookTest, NumReviewGetter) {
        Book* testBook = new Book("title", "author", "genre", 222, 0, 0);

        //Tests the GetNumReviews() function

        EXPECT_EQ(testBook->GetNumReviews(), 0);
}


#endif
