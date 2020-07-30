//
// Created by jimo on 2020/7/31.
//

#include "main.h"
#include<iostream>

using namespace std;

struct Person {
    int age;

    void addAge(); // C++可以
};

void test04() {
    // C++语言不必加struct关键字
    Person p1;
}

// C++语言中返回的是变量
void test05() {
    int a = 10;
    int b = 20;
    a > b ? a : b = 100;
    cout << "a=" << a << ",b=" << b << endl; // a=10,b=100
}

void test06() {
    const int d = 30;

    int *p = (int *) &d;
    *p = 100;
    cout << "*p=" << *p << ", d=" << d << endl; // *p=100, d=30
}

int main() {
    cout << sizeof(bool) << endl; // 1
    bool flag;
    cout << flag << endl; // 0
    flag = 100;
    cout << flag << endl; // 1

    test05();

    test06();
    return 0;
}