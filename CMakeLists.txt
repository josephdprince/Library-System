CMAKE_MINIMUM_REQUIRED(VERSION 3.2 FATAL_ERROR)

project(LibrarySystem)

if(POLICY CMP0025)
    cmake_policy(SET CMP0025 NEW)
endif()

# Enforce the C++ standard, and disable extensions.
if(NOT DEFINED CMAKE_CXX_STANDARD)
    set(CMAKE_CXX_STANDARD 17)
endif()

SET(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# if (NOT CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
#     set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror")
# endif()

SET(CMAKE_CXX_CLANG_TIDY clang-tidy)

INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/include
        /home/ubuntu/Library-System/thirdparty/mongo-cxx-driver-r3.8.1/build/install/include/mongocxx/v_noabi
        /home/ubuntu/Library-System/thirdparty/mongo-cxx-driver-r3.8.1/build/install/include/bsoncxx/v_noabi)

LIST(PREPEND CMAKE_PREFIX_PATH "/home/ubuntu/Library-System/thirdparty/mongo-cxx-driver-r3.8.1/build/src/mongocxx")
LIST(PREPEND CMAKE_PREFIX_PATH "/home/ubuntu/Library-System/thirdparty/mongo-cxx-driver-r3.8.1/build/src/bsoncxx")

FIND_PACKAGE(mongocxx REQUIRED)
FIND_PACKAGE(bsoncxx REQUIRED)

ADD_SUBDIRECTORY(googletest)

# Define a common set of source files
set(SOURCE_FILES
    src/Admin.cpp
    src/Book.cpp
    src/Composition.cpp
    src/Db.cpp
    src/Individual.cpp
    src/Library.cpp
    src/main.cpp
    src/Standard.cpp
    src/Strategy.cpp
    src/User.cpp
)

ADD_EXECUTABLE(run ${SOURCE_FILES})

# Link necessary libraries
TARGET_LINK_LIBRARIES(run PRIVATE 
    mongo::mongocxx_shared 
    mongo::bsoncxx_shared
)

# TODO: Link test with mongo
# ADD_EXECUTABLE(test 
#     tests/Unit_Test.cpp
#     ${SOURCE_FILES}
# )

# TARGET_LINK_LIBRARIES(test gtest)
# TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)
