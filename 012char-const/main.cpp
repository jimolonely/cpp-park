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

    // �޸�ptrָ�������
//     ptr[0] = 'H'; // ����ֻ����
    ptr = s2; // �����޸�����
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

    // �޸�ptrָ�������
    ptr[0] = 'H'; // �����޸�ֵ
//    ptr = s2; // �����޸�����
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
