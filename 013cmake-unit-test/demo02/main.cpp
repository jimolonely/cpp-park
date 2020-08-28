//
// Created by jack on 2020/8/28.
//

#include "message.hpp"
#include<cstdlib>
#include<iostream>

using namespace std;

int main() {

    Message hello("hello");
    cout << hello << endl;

    Message world("world");
    cout << world << endl;
    return EXIT_SUCCESS;
}

