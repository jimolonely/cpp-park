//
// Created by wangpeng417 on 2020/8/1.
//
#include <iostream>

using namespace std;

#define LENGTH 10
#define NEWLINE '\n'

static int cnt = 10;

void add() {
    static int i = 1;
    i++;
    cout << "i=" << i << ", cnt=" << cnt << endl;
}

extern int g_count;

extern void global_func();

int main() {
    cout << g_count << endl;

    cout << "Size of char : " << sizeof(char) << endl;
    cout << "Size of int : " << sizeof(int) << endl;
    cout << "Size of short int : " << sizeof(short int) << endl;
    cout << "Size of long int : " << sizeof(long int) << endl;
    cout << "Size of float : " << sizeof(float) << endl;
    cout << "Size of double : " << sizeof(double) << endl;
    cout << "Size of wchar_t : " << sizeof(wchar_t) << endl;


    typedef int meter;
    meter distance;
    distance = 10;
    cout << distance << "รื" << endl;

    enum color {
        RED, GREEN = 3, BLUE
    } c;
    c = BLUE;
    cout << RED << GREEN << BLUE << c << endl; // 0344

    short i1 = 10;

//    {
//        int mount;
//        auto int month;
//
//        register int miles;
//    }

    while (cnt--) {
        add();
    }
    return 0;
}

