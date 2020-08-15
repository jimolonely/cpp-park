
# 继承

* (A: public B)当基类由派生类私有继承时，基类的公共成员成为派生类的私有成员。因此，基类的公共成员不能被派生类的对象访问，仅能由派生类的成员函数访问。
* (A: private B)当基类被派生类公开继承时，基类的公共成员也成为派生类的公共成员。因此，基类的公共成员可以由派生类的对象以及基类的成员函数都可以访问。

## 继承字段

```c++
class Account {
public:
    float salary = 6000;
};

class Programmer : public Account {
public :
    float bonus = 5000;
};

Programmer p1;
cout << "Salary:" << p1.salary << ",Bonus:" << p1.bonus << endl; // Salary:6000,Bonus:5000
```

## 单继承-继承方法

```c++
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
```

## 类成员的可见性

* private
* protected
* public

## 方法冲突

```c++
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

int main() {

    D d;
    d.display();
}
```

现在想调用父类的display方法：
```c++
d.C1::display();
```

# 组合

```c++
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

int main() {

    Address address = Address("Beijing");
    Employee e = Employee("jimo", &address);
    e.display();
}
```

# 多态

```c++
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

int main() {

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
}
```

可以看到：

* 父类的虚方法倍重写了
* 但字段并没被覆盖

# 操作符重载

一元和二元重载

```c++
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

int main() {

    Add a1(3);
    Add a2;
    ++a1;
    a1.print(); // num is 5
    a1 + a2; // add two=13
}
```

# 接口与纯虚函数

```c++
class Plant {
public:
    virtual void grow() = 0;
};
```
