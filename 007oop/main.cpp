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
        cout << "»ÙÃðÎÒ°Ñ" << endl;
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

int main() {
    Student s1;
    s1.id = 18;
    s1.name = "jimo";

    Student s2 = Student(19, "hehe");
    s2.display();

    struct Rectangle rec = Rectangle(3, 5);
    rec.print();

    return 0;
}
