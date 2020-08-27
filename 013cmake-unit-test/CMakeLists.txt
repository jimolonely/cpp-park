cmake_minimum_required(VERSION 3.10)
project(cmake-unit-test-demo)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

add_subdirectory(src)
add_subdirectory(test)
add_subdirectory(lib/googletest)

add_executable(cmake-unit-test-demo main.cpp file1.cpp file1.h)