
# 参数化模板

也就是泛型编程。

## 函数模板

看个阶乘：
```c++
int factorial(int n) {
    if (n <= 0) {
        return 1;
    }
    return n * factorial(n - 1);
}

cout << factorial(5) << endl; // 120
```

现在做一个变体，可以支持多种类型的阶乘：

```c++
template<typename T>
T factorial1(T const &n) {
    if (n <= 0) {
        return 1;
    }
    return n * factorial1(n - 1);
}

int main() {
    cout << factorial1(5) << endl; // 120
    cout << factorial1(5.7) << endl; // 318.482
}
```

## 类模板

```c++
#include<vector>

template<class T>
class Stack {
private:
    vector<T> elems;
public:
    void push(T const &elem) {
        elems.push_back(elem);
    }

    void pop() const {
        if (elems.empty()) {
            throw out_of_range("empty stack");
        }
        elems.pop_back();
    }
};

int main() {
    Stack<int> intStack;
    Stack<string> strStack;
}
```

# 非参数化模板

就是将一种类型确定下来。

比如一个简单的例子：

```c++
template<char quote>
string quotedString(const string &origin) {
    return quote + origin + quote;
}

int main() {
    cout << quotedString<'#'>("hello") << endl; // #hello#
    cout << quotedString<'"'>("hello") << endl; // "hello"
}
```
当然，这个用类来实现更好：

```c++
template<char quote>
class QuoteString {
public:
    string origin;

    void print() {
        cout << quote + origin + quote << endl;
    }
};

int main() {
    QuoteString<'%'> q1;
    q1.origin = "hehe"; // %hehe%
    q1.print();

    QuoteString<'*'> q2;
    q2.origin = "lily";
    q2.print(); // *lily*
}
```

