cmake_minimum_required(VERSION 3.10)

# set the project name
project(MatrixTests VERSION 1.0)
enable_testing()

# set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include(FetchContent)
include(CTest)

# Download and build Google Test
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG        release-1.11.0
)
FetchContent_MakeAvailable(googletest)

# Add your project's executable
add_executable(MatrixTests main_test.cc ../src/matrix.cpp)

# Link with Google Test libraries
target_link_libraries(MatrixTests gtest gtest_main)

# Add test
include(GoogleTest)
gtest_discover_tests(MatrixTests)
