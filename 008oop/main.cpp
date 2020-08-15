//
// Created by wangpeng417 on 2020/8/1.
//
#include <iostream>

using namespace std;

class Account {
public:
    float salary = 6000;
};

class Programmer : public Account {
public :
    float bonus = 5000;
};

class Animal {
public:
    void eat() {
        cout << "Eating..." << endl;
    }
};

class Dog : public Animal {
public:
    void bark() {
        cout << "Barking..." << endl;
    }
};

class A {
    int a = 4;
    int b = 5;
public:
    int mul() {
        return a * b;
    }
};

class B : private A {
public:
    void display() {
        // a,b不能被访问
        cout << "mul a*b=" << mul() << endl;
    }
};

class C1 {
public:
    void display() {
        cout << "class C1" << endl;
    }
};

class C2 {
public:
    void display() {
        cout << "class C2" << endl;
    }
};

class D : public C1, public C2 {
public:
    void display() {
        C1::display();
        C2::display();
    }
};

class Address {
public:
    string city;

    Address(string city) {
        this->city = city;
    }
};

class Employee {
private:
    Address *address;
public:
    string name;

    Employee(string name, Address *address) {
        this->name = name;
        this->address = address;
    }

    void display() {
        cout << "name=" << name << ", address=" << address->city << endl;
    }
};

class Shape {
public:
    string color = "black";

    virtual void draw() {
        cout << "drawing..." << endl;
    }
};

class Rect : public Shape {
public:
    string color = "red";

    void draw() {
        cout << "drawing rect..." << endl;
    }
};

class Circle : public Shape {
public:
    string color = "blue";

    void draw() {
        cout << "drawing circle..." << endl;
    }
};

class Add {
private:
    int num;
public:
    Add() : num(8) {}

    Add(int i) {
        num = i;
    }

    void operator++() {
        num += 2;
    }

    void operator+(Add);

    void print() {
        cout << "num is " << num << endl;
    }
};

void Add::operator+(Add a) {
    int s = num + a.num;
    cout << "add two=" << s << endl;
}

class Plant {
public:
    virtual void grow() = 0;
};

int main() {

    Add a1(3);
    Add a2;
    ++a1;
    a1.print(); // num is 5
    a1 + a2; // add two=13

    Shape *s; // pointer
    Shape sh;
    Rect r;
    Circle c;

    s = &sh;
    s->draw(); // drawing...
    cout << s->color << endl; // black

    s = &r;
    s->draw(); // drawing rect...
    cout << s->color << endl; // black

    s = &c;
    s->draw(); // drawing circle...
    cout << s->color << endl; // black

    Address address = Address("Beijing");
    Employee e = Employee("jimo", &address);
    e.display();

    D d;
    d.display();
    d.C1::display();

    B b1;
    b1.display();

    Dog d1;
    d1.eat();
    d1.bark();

    Programmer p1;
    cout << "Salary:" << p1.salary << ",Bonus:" << p1.bonus << endl; // Salary:6000,Bonus:5000

    return 0;
}
