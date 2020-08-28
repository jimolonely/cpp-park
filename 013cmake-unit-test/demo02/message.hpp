#pragma once

#include<iosfwd>
#include<string>
#include <utility>

using namespace std;

class Message {
public:
    Message(string m) : message(std::move(m)) {}

    friend std::ostream &operator<<(std::ostream &os, Message &obj) {
        return obj.printObject(os);
    }

private:
    string message;

    ostream &printObject(std::ostream &os);
};