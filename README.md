
# 双冒号运算符

```c++
int a = 200;

void test000() {
    int a = 100;
    cout << "局部变量a=" << a << endl;
    cout << "全局变量a=" << ::a << endl;
}

/*
局部变量a=100
全局变量a=200
 */
```

# 命名空间

1. 避免命名冲突
```c++
// game1.h
#include<iostream>

namespace G1 {
    void attack();
}
// game1.cpp
#include "game1.h"

using namespace std;

void G1::attack() {
    cout << "game1 attack" << endl;
}

// game2.h
#include<iostream>

namespace G2 {
    void attack();
}
// game2.cpp
#include "game2.h"

using namespace std;

void G2::attack() {
    cout << "game2 attack" << endl;
}
```
使用
```c++
# include "001namespace/game1.h"
# include "001namespace/game2.h"

int main() {
    G1::attack();
    G2::attack();
    return 0;
}
/**
game1 attack
game2 attack
*/
```

2. 必须定义在全局作用域下

3. 命名空间可以嵌套

```c++
namespace A {
    int b = 20;

    namespace B {
        int b = 10;
    }
}

cout << A::b << endl;
cout << A::B::b << endl;
```

4. 命名空间可以随时追加内容

```c++
namespace A {
    int b = 20;

    namespace B {
        int b = 10;
    }
}

namespace A {
    int c = 100;
}
```

5. 匿名的命名空间：里面变量相当于静态的

```c++
namespace {
    int d = 100;
}
```

6. 命名空间可以起别名

```c++
namespace AA = A;
cout << AA::b << endl;
```

# using使用

```c++
namespace A {
    int b = 20;
}

void test01() {
    int a = 10;
    cout << a << endl; // 10

    // using声明，后面使用的都是A作用域的a变量
    using A::b;
    cout << b << endl; // 20
}

void test02() {
    int b = 30;
    cout << b << endl; // 30

    using namespace A;
    cout << b << endl; // 30
    cout << A::b << endl; // 20
}
```

# C++对C语言的增强

一句话：C++更严格，功能更强大。

1. 全局变量检测：C语言不会报错
```c++
int a;
int a = 10;
```

2. 函数参数检测：C语言能编译
```c++
int getArea(w, h) {
}

void test() {
    getArea(10, 20);
}
```

3. 类型转换检测: C语言不报错
```c++
void test01() {
    // malloc返回是void*
    char *p = malloc(sizeof(64));
}
```

4. 结构体增强：C语言不能加函数
```c++
struct Person {
    int age;

    // void addAge(); C++可以
};
```

5. 结构体的初始化struct：
```c++
void test04() {
    // C语言必须加struct关键字
    struct Person p1;
}

void test04() {
    // C++语言不必加struct关键字
    Person p1;
}
```

6. bool类型增强：C语言里没有bool类型
```c++
cout << sizeof(bool) << endl; // 1
bool flag;
cout << flag << endl; // 0
flag = 100;
cout << flag << endl; // 1
```

7. 三目运算符增强：

```c++
// C语言中返回的是值
void test05() {
    int a = 10;
    int b = 20;
    *(a > b ? &a : &b) = 100;
    printf("a=%d,b=%d", a, b); // a=10,b=100
}

// C++语言中返回的是变量
void test05() {
    int a = 10;
    int b = 20;
    a > b ? a : b = 100;
    cout << "a=" << a << ",b=" << b << endl; // a=10,b=100
}
```

8. const增强: C语言里局部变量的const可以被修改，C++里不行

```c++
void test06() {
    const int d = 30;

    int *p = (int *) &d;
    *p = 100;
    printf("*p=%d, d=%d\n", *p, d); // *p=100, d=100
}

void test06() {
    const int d = 30;

    int *p = (int *) &d;
    *p = 100;
    cout << "*p=" << *p << ", d=" << d << endl; // *p=100, d=30
}
```


