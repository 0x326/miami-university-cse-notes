#include "TwoArgClass.h"
#include <iostream>

TwoArgClass::TwoArgClass(int arg1, int arg2) {
    std::cout << "TwoArgClass::TwoArgClass(" << arg1 << ", " << arg2 << ")" << std::endl;
}

TwoArgClass::~TwoArgClass() {
    std::cout << "TwoArgClass::~TwoArgClass()" << std::endl;
}
