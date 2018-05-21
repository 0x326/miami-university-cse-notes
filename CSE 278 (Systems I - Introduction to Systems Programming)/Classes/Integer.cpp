#include <iostream>
#include "Integer.h"

Integer::Integer() {
    std::cout << "Integer::Integer()" << std::endl;
    this->i = 0;
}

// Fields can be auto initialized with an initializer list:
//   Constructor : fieldName(argumentName)
// Initialization occurs before the body of the constructor is executed
Integer::Integer(int i) : i(i) {
    std::cout << "Integer::Integer(" << i << ")" << std::endl;
}
