#ifndef __ADMIN_TEST_HPP__
#define __ADMIN_TEST_HPP__

#include <string>
#include <iostream>

#include "gtest/gtest.h"
#include "Admin.hpp"
#include "Library.hpp"

using namespace std;

TEST(AdminTest, AssignedAdmin) {
	Admin* testAdmin = new Admin("userName", "passWord");
	string test = testAdmin->getUserType();
	
	//Tests if admin is properly assigned.
	
	EXPECT_EQ(test, "admin");
}

TEST(AdminTest, AddBook) {
        Admin* testAdmin = new Admin("userName", "passWord");
	Book* testBook = new Book("title", "author", "genre", 0, 0, 0);
	Library* lib = new Library();
	
	if(!lib->loadUsers()) {
		std::cerr << "ERROR: Cannot load users from login.csv" << std::endl;
		exit(1);
	}

	//lib->login();
	
	//Tests the Admin addBook function
	
			
}

#endif
