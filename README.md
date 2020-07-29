
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

