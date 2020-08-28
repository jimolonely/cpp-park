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


# 生成器

有很多生成代码的工具：

```shell script
$ cmake --help
...
Generators

The following generators are available on this platform:
  Unix Makefiles               = Generates standard UNIX makefiles.
  Ninja                        = Generates build.ninja files.
  Watcom WMake                 = Generates Watcom WMake makefiles.
  CodeBlocks - Ninja           = Generates CodeBlocks project files.
  CodeBlocks - Unix Makefiles  = Generates CodeBlocks project files.
  CodeLite - Ninja             = Generates CodeLite project files.
  CodeLite - Unix Makefiles    = Generates CodeLite project files.
  Sublime Text 2 - Ninja       = Generates Sublime Text 2 project files.
  Sublime Text 2 - Unix Makefiles
                               = Generates Sublime Text 2 project files.
  Kate - Ninja                 = Generates Kate project files.
  Kate - Unix Makefiles        = Generates Kate project files.
  Eclipse CDT4 - Ninja         = Generates Eclipse CDT 4.0 project files.
  Eclipse CDT4 - Unix Makefiles= Generates Eclipse CDT 4.0 project files.
  KDevelop3                    = Generates KDevelop 3 project files.
  KDevelop3 - Unix Makefiles   = Generates KDevelop 3 project files.
```

切换生成器：比如选择Ninja
```shell script
demo01$ rm -rf build

demo01$ cmake -H. -Bbuild -G Ninja
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

demo01$ cd build/
demo01/build$ cmake --build .
[2/2] Linking CXX executable demo01

demo01/build$ ll
总用量 84
drwxr-xr-x 3 jack jack  4096 8月  28 08:38 ./
drwxrwxr-x 3 jack jack  4096 8月  28 08:38 ../
-rw-r--r-- 1 jack jack 14812 8月  28 08:38 build.ninja
-rw-r--r-- 1 jack jack 12601 8月  28 08:38 CMakeCache.txt
drwxr-xr-x 5 jack jack  4096 8月  28 08:38 CMakeFiles/
-rw-r--r-- 1 jack jack  1570 8月  28 08:38 cmake_install.cmake
-rwxr-xr-x 1 jack jack 13736 8月  28 08:38 demo01*
-rw-r--r-- 1 jack jack  8792 8月  28 08:38 .ninja_deps
-rw-r--r-- 1 jack jack   124 8月  28 08:38 .ninja_log
-rw-r--r-- 1 jack jack  1920 8月  28 08:38 rules.ninja

demo01/build$ ./demo01 
Hello, CMake world!
```


