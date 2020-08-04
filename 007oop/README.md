
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

