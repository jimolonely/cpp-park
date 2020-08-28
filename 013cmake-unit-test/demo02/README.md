# 静态依赖库

就是编译文件的打包

```shell script
cmake_minimum_required(VERSION 3.10)

project(demo02)

add_library(message STATIC message.cpp message.hpp)

add_executable(demo02 main.cpp)

target_link_libraries(demo02 message)
```

编译：
```shell script
$ cd demo02
/demo02$ cmake -H. -Bbuild
-- The C compiler identification is GNU 7.5.0
-- The CXX compiler identification is GNU 7.5.0
-- Check for working C compiler: /usr/bin/cc
-- Check for working C compiler: /usr/bin/cc -- works
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Detecting C compile features
-- Detecting C compile features - done
-- Check for working CXX compiler: /usr/bin/c++
-- Check for working CXX compiler: /usr/bin/c++ -- works
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Configuring done
-- Generating done
-- Build files have been written to: /home/jack/workspace/Git/cpp-park/013cmake-unit-test/demo02/build

/demo02$ cd build/
/demo02/build$ cmake --build .
Scanning dependencies of target message
[ 25%] Building CXX object CMakeFiles/message.dir/message.cpp.o
[ 50%] Linking CXX static library libmessage.a
[ 50%] Built target message
Scanning dependencies of target demo02
[ 75%] Building CXX object CMakeFiles/demo02.dir/main.cpp.o
[100%] Linking CXX executable demo02
[100%] Built target demo02

/demo02/build$ ll
总用量 60
drwxr-xr-x 3 jack jack  4096 8月  28 09:02 ./
drwxrwxr-x 3 jack jack  4096 8月  28 09:01 ../
-rw-r--r-- 1 jack jack 12807 8月  28 09:01 CMakeCache.txt
drwxr-xr-x 6 jack jack  4096 8月  28 09:02 CMakeFiles/
-rw-r--r-- 1 jack jack  1570 8月  28 09:01 cmake_install.cmake
-rwxr-xr-x 1 jack jack 14512 8月  28 09:02 demo02*
-rw-r--r-- 1 jack jack  3110 8月  28 09:02 libmessage.a
-rw-r--r-- 1 jack jack  5993 8月  28 09:01 Makefile

/demo02/build$ ./demo02 
This is my jimo message: 
hello
This is my jimo message: 
world
```

# 动态库

动态链接，运行时才加载的库

```shell script
add_library(message SHARED message.cpp message.hpp)
```

编译步骤和上面一样，看看有什么区别：

```shell script
$ ll
总用量 68
drwxr-xr-x 3 jack jack  4096 8月  28 21:51 ./
drwxrwxr-x 3 jack jack  4096 8月  28 21:51 ../
-rw-r--r-- 1 jack jack 12807 8月  28 21:51 CMakeCache.txt
drwxr-xr-x 6 jack jack  4096 8月  28 21:51 CMakeFiles/
-rw-r--r-- 1 jack jack  1570 8月  28 21:51 cmake_install.cmake
-rwxr-xr-x 1 jack jack 14136 8月  28 21:51 demo02*
-rwxr-xr-x 1 jack jack  8672 8月  28 21:51 libmessage.so*
-rw-r--r-- 1 jack jack  5993 8月  28 21:51 Makefile
```

可以看到：静态的后缀是a，动态是so，且可执行
```shell script
-rw-r--r-- 1 jack jack  3110 8月  28 09:02 libmessage.a
VS
-rwxr-xr-x 1 jack jack  8672 8月  28 21:51 libmessage.so*
```

# 对象库

这个待研究 TODO

# 命令解释

https://chenxiaowei.gitbook.io/cmake-cookbook/1.0-chinese/1.3-chinese

