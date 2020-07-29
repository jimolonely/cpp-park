//
// Created by jimo on 2020/7/30.
//

#ifndef CPP_PARK_TEST001_H
#define CPP_PARK_TEST001_H

#endif //CPP_PARK_TEST001_H

#include <iostream>

using namespace std;
namespace A {
    int b = 20;

    namespace B {
        int b = 10;
    }
}

namespace A {
    int c = 100;
}

void test001();