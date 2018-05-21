#include "OneArgClass.h"
#include <iostream>

OneArgClass::OneArgClass(int arg1) {
    std::cout << "OneArgClass::OneArgClass(" << arg1 << ")" << std::endl;
}

OneArgClass::~OneArgClass() {
    std::cout << "OneArgClass::~OneArgClass()" << std::endl;
}
