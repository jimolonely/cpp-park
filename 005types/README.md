
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

# 指针

是个变量，只是其存储的是另一个变量的地址。

基本用法：
```c++
int v1 = 10;
int v2[10];
cout << &v1 << endl; // 0x61fe08
cout << &v2 << endl; // 0x61fde0

int *ip;

ip = &v1; // 存储地址
cout << ip << endl; // 0x61fe08
// 取值
cout << *ip << endl; // 10
```

## 空指针指什么

```c++
int *ptr = NULL;
cout << ptr << endl; // 0
```
空指针为0，代表内存地址为0，代表不能被访问的地址。

## 指针的算术运算

### 加和减

```c++
int arr[3] = {10, 100, 200};
int *parr;
parr = arr;
for (int k = 0; k < 3; ++k) {
    cout << "k=" << k << ",地址为：" << parr << ", 值为：" << *parr << endl;
    parr++;
}
parr = &arr[2];
for (int k = 2; k >= 0; --k) {
    cout << "k=" << k << ",地址为：" << parr << ", 值为：" << *parr << endl;
    parr--;
}
```
结果：可以看到，因为是int，所以每次地址+4
```c++
k=0,地址为：0x61fdc4, 值为：10
k=1,地址为：0x61fdc8, 值为：100
k=2,地址为：0x61fdcc, 值为：200
k=2,地址为：0x61fdcc, 值为：200
k=1,地址为：0x61fdc8, 值为：100
k=0,地址为：0x61fdc4, 值为：10
```

### 指针比较

可以使用 `==,<,>`来比较。

```c++
parr = arr;
int i = 0;
while (parr <= &arr[2]) {
    cout << "i=" << i << ",地址为：" << parr << ", 值为：" << *parr << endl;
    parr++;
    i++;
}
```
结果：
```c++
i=0,地址为：0x61fdbc, 值为：10
i=1,地址为：0x61fdc0, 值为：100
i=2,地址为：0x61fdc4, 值为：200
```

## 指针数组

就是一个数组，里面元素的值为 指针，也就是地址。

```c++
int arr[3] = {10, 100, 200};
int *paa[3];
for (int l = 0; l < 3; ++l) {
    paa[l] = &arr[l];
}
for (int m = 0; m < 3; ++m) {
    cout << "m=" << m << ",地址为：" << paa[m] << ", 值为：" << *paa[m] << endl;
}
```
结果：
```c++
m=0,地址为：0x61fdb4, 值为：10
m=1,地址为：0x61fdb8, 值为：100
m=2,地址为：0x61fdbc, 值为：200
```

## 数组指针
指向数组的指针，实际上指向的起始地址，后面位置通过计算偏移量得出.

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

## 双重指针

也即是指向指针的指针。

```c++
int i1 = 100;
int *pi1;
int **ppi1;
pi1 = &i1;
ppi1 = &pi1;
cout << "i1=" << i1 << ", pi1=" << pi1 << ", *pi1=" << *pi1 << ", ppi1=" << ppi1 << ", *ppi1=" << *ppi1
     << ", **ppi1=" << **ppi1 << endl;
```
结果：
```c++
i1=100, pi1=0x61fda4, *pi1=100, ppi1=0x61fda0, *ppi1=0x61fda4, **ppi1=100
```

## 数组作为函数参数与返回值

```c++
void func1(int *arr) {}

void func2(int arr[10]) {}

void func3(int arr[]) {}
```
返回值：
```c++
int *func4() {
    int r[10];
    return r;
}
```

# 引用

引用和指针的区别：

* 引用不能为NULL
* 一旦引用被初始化，就不能再修改为另一个对象的引用
* 引用必须在创建时初始化

```c++
int c = 10;
double d = 2.3;
int &rc = c;
double &rd = d;
cout << "rd=" << rd << ", rc=" << rc << endl; // rd=2.3, rc=10
```

引用有啥用？

可以作为参数修改引用变量的值

```c++
void swap(int &t1, int &t2) {
    int t = t1;
    t1 = t2;
    t2 = t;
}

int t1 = 100;
int t2 = 200;
cout << "t1=" << t1 << ", t2=" << t2 << endl; // t1=100, t2=200
swap(t1, t2);
cout << "t1=" << t1 << ", t2=" << t2 << endl; // t1=200, t2=100
```

返回引用 ，在外面修改值

```c++
double vals[] = {1.1, 2.2, 3.3};

double &setValues(int i) {
    return vals[i];
}

for (int n = 0; n < 3; ++n) {
    cout << "vals[" << n << "]=" << vals[n] << " ";
}
cout << endl; // vals[0]=1.1 vals[1]=2.2 vals[2]=3.3
setValues(1) = 22.22;
setValues(2) = 33.33;
for (int n = 0; n < 3; ++n) {
    cout << "vals[" << n << "]=" << vals[n] << " ";
}
cout << endl; // vals[0]=1.1 vals[1]=22.22 vals[2]=33.33
```
