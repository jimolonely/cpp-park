//
// Created by jimo on 2020/7/30.
//

#include <iostream>
#include "000main.h"

using namespace std;


int a = 200;

void test000() {
    int a = 100;
    cout << "�ֲ�����a=" << a << endl;
    cout << "ȫ�ֱ���a=" << ::a << endl;
}