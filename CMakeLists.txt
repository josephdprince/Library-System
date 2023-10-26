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

INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/include)

ADD_SUBDIRECTORY(thirdparty/mongo-cxx-driver-r3.8.1)
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

# Include necessary directories for the run target
TARGET_INCLUDE_DIRECTORIES(run PRIVATE 
    ${CMAKE_SOURCE_DIR}/thirdparty/mongo-cxx-driver-r3.8.1/src/mongocxx/
    ${CMAKE_BINARY_DIR}/thirdparty/mongo-cxx-driver-r3.8.1/src/bsoncxx/
)

# Link necessary libraries
TARGET_LINK_LIBRARIES(run PRIVATE 
    mongocxx_shared 
    bsoncxx_shared
)

# TODO: Link test with mongo
# ADD_EXECUTABLE(test 
#     tests/Unit_Test.cpp
#     ${SOURCE_FILES}
# )

# TARGET_LINK_LIBRARIES(test gtest)
# TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)
