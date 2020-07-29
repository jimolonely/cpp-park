//
// Created by jimo on 2020/7/30.
//

#include <iostream>
#include "000main.h"

using namespace std;


int a = 200;

void test000() {
    int a = 100;
    cout << "局部变量a=" << a << endl;
    cout << "全局变量a=" << ::a << endl;
}