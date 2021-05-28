CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

ADD_SUBDIRECTORY(googletest)

SET(CMAKE_CXX_STANDARD 11)

ADD_EXECUTABLE(run main.cpp User.cpp Admin.cpp Lists.hpp Standard.cpp Strategy.hpp Library.cpp Book.cpp)

ADD_EXECUTABLE(test
    Unit_Test.cpp
)

TARGET_LINK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)
