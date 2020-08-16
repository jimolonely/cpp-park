
# const char * const ptr

这俩 const 分别修饰的什么？ 还需要分开讨论

## const char* ptr

```c++
void testConstChar() {
    char s1[] = "hello";
    char s2[] = "world";

    const char *ptr = s1; // 等价于： char const *ptr = s1;
    for (int i = 0; i < 5; ++i) {
        cout << ptr[i];
    }
    cout << endl;

    // 修改ptr指向的内容
    // ptr[0] = 'H'; // 报错，只读的
    ptr = s2; // 可以修改引用
    for (int i = 0; i < 5; ++i) {
        cout << ptr[i];
    }
    cout << endl;
}
```

## char* const ptr

```c++
void testCharStarConst() {
    char s1[] = "hello";
    char s2[] = "world";

    char *const ptr = s1;
    for (int i = 0; i < 5; ++i) {
        cout << ptr[i];
    }
    cout << endl;

    // 修改ptr指向的内容
    ptr[0] = 'H'; // 可以修改值
//    ptr = s2; // 不能修改引用
    for (int i = 0; i < 5; ++i) {
        cout << ptr[i];
    }
    cout << endl;
}
```

## 所以

当我们2个都加上时，那就啥都不能改了呗！

