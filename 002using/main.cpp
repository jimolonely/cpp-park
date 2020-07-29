//
// Created by jimo on 2020/7/30.
//

#include "main.h"
#include<iostream>

using namespace std;

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

int main() {

    test01();
    test02();

    return 0;
}