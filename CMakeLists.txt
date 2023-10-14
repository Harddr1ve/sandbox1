# FILEPATH: /home/harddrive/DEV/sandbox/CMakeLists.txt

cmake_minimum_required(VERSION 3.10)

project(MyProject)

# Add main.cpp and matrix.cpp to the executable
add_subdirectory(src)

# Add tests from the tests folder
enable_testing()
add_subdirectory(tests)
