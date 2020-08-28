cmake_minimum_required(VERSION 3.10)

project(demo03)

set(USE_LIB ON)

message(STATUS "全部编译到一个库：${USE_LIB}")

set(BUILD_SHARED_LIBS OFF)

list(APPEND _sources message.hpp message.cpp)

if (USE_LIB)
    add_library(message ${_sources})
    add_executable(demo03 main.cpp)
    target_link_libraries(demo03 message)
else ()
    add_executable(demo03 main.cpp ${_sources})
endif ()