#include <iostream>
#include "000binocular_operator/000main.h"
# include "001namespace/game1.h"
# include "001namespace/game2.h"
# include "001namespace/test001.h"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;

    test000();

    G1::attack();
    G2::attack();

    test001();

    return 0;
}
