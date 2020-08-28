
# if-else

```shell script
cmake_minimum_required(VERSION 3.10)

project(demo03)

set(USE_LIB OFF)

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
```
可以看到因为Use_LIB为OFF，所以全部文件编译到一个文件里。

```shell script
demo03/build$ cmake ..
-- 全部编译到一个库：OFF
-- Configuring done
-- Generating done
-- Build files have been written to: /home/jack/workspace/Git/cpp-park/013cmake-unit-test/demo03/build
demo03/build$ cmake --build .
Scanning dependencies of target demo03
[ 33%] Building CXX object CMakeFiles/demo03.dir/main.cpp.o
[ 66%] Linking CXX executable demo03
[100%] Built target demo03
demo03/build$ ll
总用量 56
drwxr-xr-x 3 jack jack  4096 8月  28 22:06 ./
drwxrwxr-x 3 jack jack  4096 8月  28 22:06 ../
-rw-r--r-- 1 jack jack 12752 8月  28 22:05 CMakeCache.txt
drwxr-xr-x 5 jack jack  4096 8月  28 22:06 CMakeFiles/
-rw-r--r-- 1 jack jack  1570 8月  28 22:05 cmake_install.cmake
-rwxr-xr-x 1 jack jack 14512 8月  28 22:06 demo03*
-rw-r--r-- 1 jack jack  5585 8月  28 22:06 Makefile
demo03/build$ ./demo03 
This is my jimo message: 
hello
This is my jimo message: 
world
```
如果改为ON：那就是静态链接库了

```shell script
demo03/build$ cmake ..
-- 全部编译到一个库：ON
-- Configuring done
-- Generating done
-- Build files have been written to: /home/jack/workspace/Git/cpp-park/013cmake-unit-test/demo03/build
demo03/build$ cmake --build .
Scanning dependencies of target message
[ 25%] Building CXX object CMakeFiles/message.dir/message.cpp.o
[ 50%] Linking CXX static library libmessage.a
[ 50%] Built target message
Scanning dependencies of target demo03
[ 75%] Linking CXX executable demo03
[100%] Built target demo03
demo03/build$ ll
总用量 60
drwxr-xr-x 3 jack jack  4096 8月  28 22:09 ./
drwxrwxr-x 3 jack jack  4096 8月  28 22:08 ../
-rw-r--r-- 1 jack jack 12807 8月  28 22:09 CMakeCache.txt
drwxr-xr-x 6 jack jack  4096 8月  28 22:09 CMakeFiles/
-rw-r--r-- 1 jack jack  1570 8月  28 22:05 cmake_install.cmake
-rwxr-xr-x 1 jack jack 14512 8月  28 22:09 demo03*
-rw-r--r-- 1 jack jack  3110 8月  28 22:09 libmessage.a
-rw-r--r-- 1 jack jack  5993 8月  28 22:09 Makefile
```
