
# 双冒号运算符

```c++
int a = 200;

void test000() {
    int a = 100;
    cout << "局部变量a=" << a << endl;
    cout << "全局变量a=" << ::a << endl;
}
```

