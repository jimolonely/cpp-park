//
// Created by wangpeng417 on 2020/8/1.
//
#include <iostream>

using namespace std;

class Student {
public:

    int id;
    string name;
    static int totalCount;

    Student() {
        cout << "Student()" << endl;
        totalCount++;
    }

    Student(int id, string name) {
        this->id = id;
        this->name = name;
        totalCount++;
    }

    ~Student() {
        cout << "毁灭我把" << endl;
    }

    void display() {
        cout << "id:" << id << ",name:" << name << ",totalCount:" << totalCount << endl;
    }
};

int Student::totalCount = 0;

struct Rectangle {
    int w;
    int h;

    Rectangle(int w, int h) {
        this->w = w;
        this->h = h;
    }

    void print() {
        cout << "area:" << (w * h) << endl;
    }
};

enum week {
    MONDAY = 0,
    TUESDAY,
    WEDNESDAY
};

class Box {
private:
    int length;
public:
    Box() : length(0) {}

    friend int printLength(Box);
};

int printLength(Box b) {
    b.length += 10;
    cout << "b.length=" << b.length << endl;
    return b.length;
}

class B; // 先声明，后定义
class A {
    int x;
public:
    void setData(int x) {
        this->x = x;
    }

    friend void min(A, B);
};

class B {
    int y;
public:
    void setData(int y) {
        this->y = y;
    }

    friend void min(A, B);
};

void min(A a, B b) {
    if (a.x <= b.y) {
        cout << a.x << endl;
    } else {
        cout << b.y << endl;
    }
}

class C {
    int x = 5;

    friend class D;
};

class D {
public:
    void display(C &c) {
        cout << "c.x=" << c.x << endl;
    }
};

int main() {
    C c;
    D d;
    d.display(c); // c.x=5

    A a1;
    B b1;
    a1.setData(10);
    b1.setData(20);
    min(a1, b1); // 10

    Box b;
    printLength(b); // b.length=10


    Student s1;
    s1.id = 18;
    s1.name = "jimo";

    Student s2 = Student(19, "hehe");
    s2.display();

    struct Rectangle rec = Rectangle(3, 5);
    rec.print();

    week day;
    day = TUESDAY;
    cout << day << endl;

    return 0;
}
