//
// Created by jimo on 2020/7/31.
//

#include <stdio.h>
#include <stdlib.h>

int a;
int a = 10;

int getArea(w, h) {
}

void test() {
    getArea(10, 20);
}

void test01() {
    // malloc返回是void*
    char *p = malloc(sizeof(64));
}

struct Person {
    int age;

    // void addAge(); C++可以
};

void test04() {
    // C语言必须加struct关键字
    struct Person p1;
}

//bool flag;

// C语言中返回的是值
void test05() {
    int a = 10;
    int b = 20;
    *(a > b ? &a : &b) = 100;
    printf("a=%d,b=%d\n", a, b); // a=10,b=100
}

const int c = 1000;

void test06() {
    const int d = 30;

    int *p = (int *) &d;
    *p = 100;
    printf("*p=%d, d=%d\n", *p, d); // *p=100, d=100
}

//int main() {
//    test05();
//    test06();
//    return 0;
//}

