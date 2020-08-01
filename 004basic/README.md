
# 数据类型

```c++
cout << "Size of char : " << sizeof(char) << endl;
cout << "Size of int : " << sizeof(int) << endl;
cout << "Size of short int : " << sizeof(short int) << endl;
cout << "Size of long int : " << sizeof(long int) << endl;
cout << "Size of float : " << sizeof(float) << endl;
cout << "Size of double : " << sizeof(double) << endl;
cout << "Size of wchar_t : " << sizeof(wchar_t) << endl;
```
结果：
```c++
Size of char : 1
Size of int : 4
Size of short int : 2
Size of long int : 4
Size of float : 4
Size of double : 8
Size of wchar_t : 2
```

# typedef：给类型创建新的名字

```c++
    typedef int meter;
    meter distance;
    distance = 10;
    cout << distance << "米" << endl;
```

# enum:枚举类型

```c++
enum color {
    RED, GREEN = 3, BLUE
} c;
c = BLUE;
cout << RED << GREEN << BLUE << c << endl; // 0344
```

# 定义常量

1. 使用`#define`
```c++
#define LENGTH 10
#define NEWLINE '\n'
```
2. 使用const
```c++
const char NEWLINE = '\n';
```

# 存储类

定义一些变量或函数的作用域和声明周期。

## auto

默认: 在C++11中已经删除

```c++
{
    int mount;
    auto int month;
}
```
## register

寄存器：声明变量应该存在寄存器而不是内存，所以其不应该使用 `&` 符号，因为压根没有内存地址

**在C++17中已经不兼容**

```c++
{
    register int miles;
}
```

## static

相当于静态成员，不被每次销毁创建

```c++
static int cnt = 10;

void add() {
    static int i = 1;
    i++;
    cout << "i=" << i << ", cnt=" << cnt << endl;
}

int main(){
    while (cnt--) {
        add();
    }
return 0;
}
```
结果：
```c++
i=2, cnt=9
i=3, cnt=8
i=4, cnt=7
i=5, cnt=6
i=6, cnt=5
i=7, cnt=4
i=8, cnt=3
i=9, cnt=2
i=10, cnt=1
i=11, cnt=0
```

## extern

全局变量声明，在全部文件里都可访问，所以不建议给初始值。

```c++
extern int g_count;
extern void global_func();
```

# 运算符

1. 算术运算符: `+,-,*,/,%,++,--`

2. 关系运算符： `==,!=,>,<,>=,<=`

3. 逻辑运算符： `&&,||,!`

4. bit运算符： `&,|,^, ~,<<,>>`

5. 其他操作符：
```c++
sizeof
con ? X:Y
. 和 ->
强转，比如 int(2.2)
&: 取变量的地址
*: 指向一个变量
```

# 常用库

```c++
#include <cmath>
#include <cstdlib>
#include <ctime>

cout << sin(60) << endl; // -0.304811
cout << rand() << endl; // 41
cout << time(nullptr) << endl; // 1596274149
```


