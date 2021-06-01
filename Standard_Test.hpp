#ifndef __STANDARD_TEST_HPP__
#define __STANDARD_TEST_HPP__

#include "gtest/gtest.h"
#include "Standard.hpp"

TEST(StandardTest, checkoutBook) {
        Library* lib = new Library();
        std::string result = "";

        if (lib->Checkout(1)) {
                result = "success";
        }
        else {
                result = "fail";
        }

        EXPECT_EQ(result, "fail");
}

TEST(StandardTest, returnBook) {
        Library* lib = new Library();
        std::string result = "";

        if (lib->Return(1)) {
                result = "success";
        }
        else {
                result = "fail";
        }

        EXPECT_EQ(result, "fail");
}

#endif
