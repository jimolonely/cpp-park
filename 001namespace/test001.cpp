//
// Created by jimo on 2020/7/30.
//

#include "test001.h"

void test001() {
    cout << A::b << endl;
    cout << A::B::b << endl;

    namespace AA = A;
    cout << AA::b << endl;
};

namespace {
    int d = 100;
}