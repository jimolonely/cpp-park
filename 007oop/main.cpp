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
    }

    Student(int id, string name) {
        this->id = id;
        this->name = name;
    }

    ~Student() {
        cout << "»ÙÃðÎÒ°Ñ" << endl;
    }

    void display() {
        cout << "id:" << id << ",name:" << name << ",totalCount:" << totalCount << endl;
    }
};

int main() {
    Student s1;
    s1.id = 18;
    s1.name = "jimo";

    Student s2 = Student(19, "hehe");
    s2.display();

    int Student::totalCount = 100;
    s2.display();

    return 0;
}
