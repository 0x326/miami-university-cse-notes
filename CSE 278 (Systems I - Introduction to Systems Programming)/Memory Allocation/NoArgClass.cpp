#include "NoArgClass.h"
#include <iostream>

NoArgClass::NoArgClass() {
    std::cout << "NoArgClass::NoArgClass()" << std::endl;
}

NoArgClass::~NoArgClass() {
    std::cout << "NoArgClass::~NoArgClass()" << std::endl;
}
