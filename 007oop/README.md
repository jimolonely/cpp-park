
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

静态属性

