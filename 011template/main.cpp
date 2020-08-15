//
// Created by wangpeng417 on 2020/8/1.
//
#include <iostream>

using namespace std;

int factorial(int n) {
    if (n <= 0) {
        return 1;
    }
    return n * factorial(n - 1);
}

template<typename T>
T factorial1(T const &n) {
    if (n <= 0) {
        return 1;
    }
    return n * factorial1(n - 1);
}

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

//#include<string>

template<char quote>
string quotedString(const string &origin) {
    return quote + origin + quote;
}

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

    cout << quotedString<'#'>("hello") << endl; // #hello#
    cout << quotedString<'"'>("hello") << endl; // "hello"

    Stack<int> intStack;
    Stack<string> strStack;

    cout << factorial1(5) << endl; // 120
    cout << factorial1(5.7) << endl; // 318.482

    cout << factorial(5) << endl; // 120

    return 0;
}
