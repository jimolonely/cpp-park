
#include "message.hpp"

#include<iostream>
#include<string>

ostream &Message::printObject(ostream &os) {
    os << "This is my jimo message: " << endl;
    os << message;
    return os;
}
