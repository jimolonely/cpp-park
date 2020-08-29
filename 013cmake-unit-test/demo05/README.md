
# 编译类型

由参数：CMAKE_BUILD_TYPE指定

* Debug：用于在没有优化的情况下，使用带有调试符号构建库或可执行文件。
* Release：用于构建的优化的库或可执行文件，不包含调试符号。
* RelWithDebInfo：用于构建较少的优化库或可执行文件，包含调试符号。
* MinSizeRel：用于不增加目标代码大小的优化方式，来构建库或可执行文件。

# 测试

默认是没有设的：

```shell script
$ cmake --system-information | grep BUILD_TYPE
CMAKE_BUILD_TYPE == ""
CMAKE_BUILD_TYPE ""
```

我们设置下,并打印：

```shell script
if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release CACHE STRING "Build type" FORCE)
endif ()
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")

message(STATUS "C flags, Debug configuration: ${CMAKE_C_FLAGS_DEBUG}")
message(STATUS "C flags, Release configuration: ${CMAKE_C_FLAGS_RELEASE}")
message(STATUS "C flags, Release configuration with Debug info: ${CMAKE_C_FLAGS_RELWITHDEBINFO}")
message(STATUS "C flags, minimal Release configuration: ${CMAKE_C_FLAGS_MINSIZEREL}")
message(STATUS "C++ flags, Debug configuration: ${CMAKE_CXX_FLAGS_DEBUG}")
message(STATUS "C++ flags, Release configuration: ${CMAKE_CXX_FLAGS_RELEASE}")
message(STATUS "C++ flags, Release configuration with Debug info: ${CMAKE_CXX_FLAGS_RELWITHDEBINFO}")
message(STATUS "C++ flags, minimal Release configuration: ${CMAKE_CXX_FLAGS_MINSIZEREL}")
```
结果：

```shell script
demo05$ cmake -H. -Bbuild
...
-- Build type: Release
-- C flags, Debug configuration: -g
-- C flags, Release configuration: -O3 -DNDEBUG
-- C flags, Release configuration with Debug info: -O2 -g -DNDEBUG
-- C flags, minimal Release configuration: -Os -DNDEBUG
-- C++ flags, Debug configuration: -g
-- C++ flags, Release configuration: -O3 -DNDEBUG
-- C++ flags, Release configuration with Debug info: -O2 -g -DNDEBUG
-- C++ flags, minimal Release configuration: -Os -DNDEBUG
```
切换构建类型
```shell script
demo05$ cmake -D CMAKE_BUILD_TYPE=Debug -H. -Bbuild
-- Build type: Debug
...
```

