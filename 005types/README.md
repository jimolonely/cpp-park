
# 字符串

```c++
char s1[5] = {'a', 'b', 'c', 'd', '\0'};
char s2[] = "abcde";
cout << s1 << "," << s2 << endl; // abcd,abcde
```
常用字符串函数
```c++
#include<cstring>

// 常用字符串函数
char str1[10] = "hello";
char str2[10] = "jimo";
char str3[10];

// copy
strcpy(str3, str1);
cout << str3 << endl; // hello
// concat
strcat(str1, str2); // hellojimo
cout << str1 << endl;
// length
cout << strlen(str1) << endl; // 9
// compare
cout << strcmp(str1, str2) << endl; // -1
```
上面是C语言中通用函数，下面是C++中定义的 string 类。

```c++
#include<string>

string ss1 = "Hello";
string ss2 = "Jimo";
string ss3;
// copy
ss3 = ss1;
cout << ss3 << endl; // Hello
// concat
ss1 = ss1 + ss2;
cout << ss1 << endl; // HelloJimo
// length
cout << ss1.size() << endl; // 9
// compare
cout << ss1.compare(ss2) << endl; // -1
```


# 数组指针

```c++
double balance[5] = {100.0, 2, 5, 89, 102};
double *p;
p = balance;
for (int i = 0; i < 5; ++i) {
    cout << "balance[i]=" << balance[i] << ", *(p+i)=" << *(p + i) << ", *(balance+i)=" << *(balance + i) << endl;
}
```
结果：当然都能访问
```c++
balance[i]=100, *(p+i)=100, *(balance+i)=100
balance[i]=2, *(p+i)=2, *(balance+i)=2
balance[i]=5, *(p+i)=5, *(balance+i)=5
balance[i]=89, *(p+i)=89, *(balance+i)=89
balance[i]=102, *(p+i)=102, *(balance+i)=102
```

