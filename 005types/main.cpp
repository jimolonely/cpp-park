//
// Created by wangpeng417 on 2020/8/1.
//
#include <iostream>
#include<cstring>
#include<string>

using namespace std;

void swap(int &t1, int &t2) {
    int t = t1;
    t1 = t2;
    t2 = t;
}

double vals[] = {1.1, 2.2, 3.3};

double &setValues(int i) {
    return vals[i];
}

int main() {

    double balance[5] = {100.0, 2, 5, 89, 102};
    double *p;
    p = balance;
    for (int i = 0; i < 5; ++i) {
        cout << "balance[i]=" << balance[i] << ", *(p+i)=" << *(p + i) << ", *(balance+i)=" << *(balance + i) << endl;
    }

    int a[5][2] = {{0, 0},
                   {1, 2},
                   {2, 4},
                   {3, 6},
                   {4, 8}};
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 2; j++) {
            cout << "a[" << i << "][" << j << "]: ";
            cout << a[i][j] << endl;

        }
    }

    char s1[5] = {'a', 'b', 'c', 'd', '\0'};
    char s2[] = "abcde";
    cout << s1 << "," << s2 << endl;

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

    int v1 = 10;
    int v2[10];
    cout << &v1 << endl; // 0x61fe08
    cout << &v2 << endl; // 0x61fde0

    int *ip;

    ip = &v1; // 存储地址
    cout << ip << endl; // 0x61fe08
    // 取值
    cout << *ip << endl; // 10

    int *ptr = NULL;
    cout << ptr << endl; // 0

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

    parr = arr;
    int i = 0;
    while (parr <= &arr[2]) {
        cout << "i=" << i << ",地址为：" << parr << ", 值为：" << *parr << endl;
        parr++;
        i++;
    }

    int *paa[3];
    for (int l = 0; l < 3; ++l) {
        paa[l] = &arr[l];
    }
    for (int m = 0; m < 3; ++m) {
        cout << "m=" << m << ",地址为：" << paa[m] << ", 值为：" << *paa[m] << endl;
    }

    int i1 = 100;
    int *pi1;
    int **ppi1;
    pi1 = &i1;
    ppi1 = &pi1;
    cout << "i1=" << i1 << ", pi1=" << pi1 << ", *pi1=" << *pi1 << ", ppi1=" << ppi1 << ", *ppi1=" << *ppi1
         << ", **ppi1=" << **ppi1 << endl;

    int c = 10;
    double d = 2.3;
    int &rc = c;
    double &rd = d;
    cout << "rd=" << rd << ", rc=" << rc << endl; // rd=2.3, rc=10

    int t1 = 100;
    int t2 = 200;
    cout << "t1=" << t1 << ", t2=" << t2 << endl; // t1=100, t2=200
    swap(t1, t2);
    cout << "t1=" << t1 << ", t2=" << t2 << endl; // t1=200, t2=100

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

    return 0;
}


void func1(int *arr) {}

void func2(int arr[10]) {}

void func3(int arr[]) {}

int *func4() {
    int r[10];
    return r;
}
