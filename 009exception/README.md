
# 域名空间

```c++
namespace first {
    void hello() {
        cout << "hello first" << endl;
    }
}
namespace second {
    void hello() {
        cout << "hello second" << endl;
    }
}

int main() {

    first::hello();
    second::hello();
}
```

# 异常捕获

主要在 `std` 域名空间下

## 异常类型

* std::exception
* std::logic_failure
    * std::domain_error
    * std::invalid_argument
    * std::length_error
    * std::out_of_range
* std::runtime_error
    * std::overflow_error
    * std::range_error
    * std::underflow_error
* std::bad_exception
* std::bad_cast
* std::bad_typeid
* std::bad_alloc

## 捕获

```c++
void divide(int x, int y) {
    if (y == 0) {
        throw "divide by zero";
    }
    cout << x / y << endl;
}

int main() {

    try {
        divide(2, 0);
    } catch (const char *e) {
        cerr << e << endl; // divide by zero
    }
}
```

## 自定义异常

```c++
class MyZeroExp : public exception {
public:
    const char *what() const noexcept override {
        return "zero divided";
    }
};

void divide2(int x, int y) {
    if (y == 0) {
        MyZeroExp z;
        throw z;
    }
    cout << x / y << endl;
}

int main() {

    try {
        divide2(2, 0);
    } catch (exception &e) {
        cout << e.what() << endl;// zero divided
    }
}
```

# 高级

为何不能捕获所有异常

TODO 