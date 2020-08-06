
# OOP基础

## 构造

```c++
class Student {
public:

    int id;
    string name;

    Student() {
        cout << "Student()" << endl;
    }

    Student(int id, string name) {
        this->id = id;
        this->name = name;
    }

    void display() {
        cout << "id:" << id << ",name:" << name << endl;
    }
};
```

## 析构

```c++
~Student() {
    cout << "毁灭我把" << endl;
}
```

## 创建对象

```c++
    Student s1;
    s1.id = 18;
    s1.name = "jimo";

    Student s2 = Student(19, "hehe");
    s2.display();
```

## static属性

静态属性:必须在全局初始化.

```c++
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
};

int Student::totalCount = 0;

int main() {
    Student s1;
}
```

## C++增强版 struct

```c++
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

struct Rectangle rec = Rectangle(3, 5);
rec.print();
```

结构体和类的区别

* 结构体默认属性都是public的
* class里不修饰是private的

## 枚举

默认从0开始

```c++
enum week {
    MONDAY = 0,
    TUESDAY,
    WEDNESDAY
};

    week day;
    day = TUESDAY;
    cout << day << endl; // 1
```

## 友元friend

### 友元函数

使用被friend修饰的友元函数可以访问类中的private和protected修饰的属性和数据。

特点如下：

* 函数作用域不在声明他的类中
* 不能用类的实例去调用
* 可以被定义在private和public块里

```c++
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

int main() {
    Box b;
    printLength(b); // b.length=10
}
```
再来个同时贯穿多个类的示例

```c++
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

int main() {
    A a1;
    B b1;
    a1.setData(10);
    b1.setData(20);
    min(a1, b1); // 10
}
```

### 友元类

友元类可以访问声明他的类里的private和protected修饰的成员。

```c++
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
}
```


