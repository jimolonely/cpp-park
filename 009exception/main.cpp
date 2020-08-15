//
// Created by wangpeng417 on 2020/8/1.
//
#include <iostream>

using namespace std;

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

void divide(int x, int y) {
    if (y == 0) {
        throw "divide by zero";
    }
    cout << x / y << endl;
}

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

    try {
        divide(2, 0);
    } catch (const char *e) {
        cerr << e << endl;
    }

    first::hello();
    second::hello();

    return 0;
}
