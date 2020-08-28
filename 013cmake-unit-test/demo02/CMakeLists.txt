cmake_minimum_required(VERSION 3.10)

project(demo02)

add_library(message STATIC message.cpp message.hpp)

add_executable(demo02 main.cpp)

target_link_libraries(demo02 message)