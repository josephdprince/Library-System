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

TEST(AdminTest, addBook) {
	//Tested in Library_Test.hpp	
}

TEST(AdminTest, remBook) {
	//Tested in Library_Test.hpp
}

#endif
