//
// Created by wangpeng417 on 2020/8/1.
//
#include <iostream>
#include<cstring>
#include<string>

using namespace std;


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

    // ³£ÓÃ×Ö·û´®º¯Êý
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

    return 0;
}

