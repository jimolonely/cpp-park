//
// Created by wangpeng417 on 2020/8/1.
//
#include <iostream>

using namespace std;

void testConstChar() {
    char s1[] = "hello";
    char s2[] = "world";

//    const char *ptr = s1;
    char const *ptr = s1;
    for (int i = 0; i < 5; ++i) {
        cout << ptr[i];
    }
    cout << endl;

    // 修改ptr指向的内容
//     ptr[0] = 'H'; // 报错，只读的
    ptr = s2; // 可以修改引用
    for (int i = 0; i < 5; ++i) {
        cout << ptr[i];
    }
    cout << endl;
}

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

int main() {

    testCharStarConst();

    testConstChar();

    return 0;
}
