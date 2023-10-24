CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

project(LibrarySystem)

ADD_SUBDIRECTORY(googletest)

SET(CMAKE_CXX_STANDARD 17)

ADD_EXECUTABLE(run src/Admin.cpp src/Book.cpp src/Composition.cpp src/Individual.cpp src/Library.cpp src/main.cpp src/Standard.cpp src/Strategy.cpp src/User.cpp)

ADD_EXECUTABLE(test tests/Unit_Test.cpp src/Admin.cpp src/Book.cpp src/Composition.cpp src/Individual.cpp src/Library.cpp src/Standard.cpp src/Strategy.cpp src/User.cpp)

TARGET_LINK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)
