
# 指定编译器

有哪些编译语言

* C
* CXX
* Fortran

对应的参数为： `CMAKE_<LANG>_COMPILER`, LANG为 `C, CXX, FC`

## 指定的方式

1. 显示指定（推荐）

    ````shell script
    cmake -D CMAKE_CXX_COMPILER=g++-9 ..
    ````

2. 通过环境变量隐式指定

    ```shell script
    env CXX=clang++
    ```

# 查看系统信息

```shell script
$ cmake --system-information | grep _COMPILER
CMAKE_CXX_COMPILER == "/usr/bin/c++"
CMAKE_C_COMPILER == "/usr/bin/cc"
CMAKE_COMPILER_IS_GNUCC == "1"
CMAKE_COMPILER_IS_GNUCXX == "1"
...
```

查看下装载了哪些编译器：

```shell script
$ cmake --system-information | grep _COMPILER_LOADED
CMAKE_CXX_COMPILER_LOADED "1"
CMAKE_C_COMPILER_LOADED "1"
```

上面的C和CXX也可以在CMakeLists.txt来查询：

```shell script
cmake_minimum_required(VERSION 3.10)

project(demo04)

message(STATUS "Is the C++ compiler loaded? ${CMAKE_CXX_COMPILER_LOADED}")
if (CMAKE_CXX_COMPILER_LOADED)
    message(STATUS "The C++ compiler ID is: ${CMAKE_CXX_COMPILER_ID}")
    message(STATUS "Is the C++ from GNU? ${CMAKE_COMPILER_IS_GNUCXX}")
    message(STATUS "The C++ compiler version is: ${CMAKE_CXX_COMPILER_VERSION}")
endif ()

message(STATUS "Is the C compiler loaded? ${CMAKE_C_COMPILER_LOADED}")
if (CMAKE_C_COMPILER_LOADED)
    message(STATUS "The C compiler ID is: ${CMAKE_C_COMPILER_ID}")
    message(STATUS "Is the C from GNU? ${CMAKE_COMPILER_IS_GNUCC}")
    message(STATUS "The C compiler version is: ${CMAKE_C_COMPILER_VERSION}")
endif ()
```

结果：
```shell script
demo04$ cmake -H. -Bbuild
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
-- Is the C++ compiler loaded? 1
-- The C++ compiler ID is: GNU
-- Is the C++ from GNU? 1
-- The C++ compiler version is: 7.5.0
-- Is the C compiler loaded? 1
-- The C compiler ID is: GNU
-- Is the C from GNU? 1
-- The C compiler version is: 7.5.0
-- Configuring done
-- Generating done
```