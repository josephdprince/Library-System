CMAKE_MINIMUM_REQUIRED(VERSION 3.2 FATAL_ERROR)

project(LibrarySystem)

if(POLICY CMP0025)
    cmake_policy(SET CMP0025 NEW)
endif()

# Enforce the C++ standard, and disable extensions.
if(NOT DEFINED CMAKE_CXX_STANDARD)
    set(CMAKE_CXX_STANDARD 17)
endif()

set(CMAKE_CXX_EXTENSIONS OFF)

# if (NOT CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
#     set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror")
# endif()

list(APPEND CMAKE_PREFIX_PATH "thirdparty/mongo-cxx-driver-r3.8.1/src/mongocxx")
list(APPEND CMAKE_PREFIX_PATH "thirdparty/mongo-cxx-driver-r3.8.1/src/bsoncxx")
find_package(mongocxx REQUIRED)
find_package(bsoncxx REQUIRED)

ADD_SUBDIRECTORY(thirdparty/mongo-cxx-driver-r3.8.1)
ADD_SUBDIRECTORY(googletest)

ADD_EXECUTABLE(run src/Admin.cpp src/Book.cpp src/Composition.cpp src/Db.cpp src/Individual.cpp src/Library.cpp src/main.cpp src/Standard.cpp src/Strategy.cpp src/User.cpp)
ADD_EXECUTABLE(test tests/Unit_Test.cpp src/Admin.cpp src/Book.cpp src/Composition.cpp src/Db.cpp src/Individual.cpp src/Library.cpp src/Standard.cpp src/Strategy.cpp src/User.cpp)

TARGET_INCLUDE_DIRECTORIES(run PRIVATE thirdparty/mongo-cxx-driver-r3.8.1/src)
TARGET_LINK_LIBRARIES(run PRIVATE mongocxx_shared bsoncxx_shared)
TARGET_LINK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)
