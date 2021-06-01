#ifndef __LIBRARY_TEST_HPP__
#define __LIBRARY_TEST_HPP__

#include <iostream>
#include <string>

#include "gtest/gtest.h"
#include "Library.hpp"

using namespace std;

TEST(LibraryTest, DisplayGenre) {
	//This test only relies on Getter functions working as intended.
	//Done in Book_Test.hpp
}

TEST(LibraryTest, DisplayAll) {
        //This test only relies on Getter functions working as intended.
        //Done in Book_Test.hpp
}


TEST(LibraryTest, FindBook) {
	Library* lib = new Library();
	
	if(!lib->loadUsers()) {
		cerr << "ERROR: Cannot load users from login.csv" << endl;
		exit(1);
	}

	if(!lib->loadBooks()) {
		cerr << "ERROR: Cannot load books from booklists.csv" << endl;
                exit(1);
	}

	Book* testBook = lib->FindBook(2);
	
	EXPECT_EQ(testBook->GetTitle(), "A Confederacy of Dunces");
}

TEST(LibraryTest, LoadBooks) {
	Library* lib = new Library();
	string result = "";

	if (lib->loadBooks()) {
		result = "success";
	}
	else {
		result = "failure";
	}

	EXPECT_EQ(result, "success");
}

TEST(LibraryTest, LoadUsers) {
        Library* lib = new Library();
        string result = "";

        if (lib->loadUsers()) {
                result = "success";
        }
        else {
                result = "failure";
        }

        EXPECT_EQ(result, "success");
}

TEST(LibraryTest, CreateNewUser) {
	
}

TEST(LibraryTest, Checkout) {
	//This test relies on Standard::checkoutBook(...)
	//Done in Standard_Test.hpp
}

TEST(LibraryTest, Return) {
	//This test relies on Standard::returnBook(...)
	//Done in Standard_Test.hpp
}


#endif
