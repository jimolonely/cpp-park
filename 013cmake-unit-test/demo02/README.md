# 静态依赖库

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

# 命令解释

https://chenxiaowei.gitbook.io/cmake-cookbook/1.0-chinese/1.3-chinese

