# hello world

下面等价于：
```shell script
$ mkdir build
$ cd build
$ cmake ..
```
简洁：
```shell script
013cmake-unit-test/demo01$ cmake -H. -Bbuild
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
-- Build files have been written to: /home/jack/workspace/Git/cpp-park/013cmake-unit-test/demo01/build
```

然后构建可执行程序：

```shell script
$ cd build
$ cmake --build .
Scanning dependencies of target demo01
[ 50%] Building CXX object CMakeFiles/demo01.dir/main.cpp.o
[100%] Linking CXX executable demo01
[100%] Built target demo01

$ ./demo01 
Hello, CMake world!
```





