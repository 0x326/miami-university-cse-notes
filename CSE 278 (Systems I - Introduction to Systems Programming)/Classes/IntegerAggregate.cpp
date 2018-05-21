#include <iostream>
#include "IntegerAggregate.h"

// Reference variables, such as ``d``, must be initialized in the initializer list
IntegerAggregate::IntegerAggregate(Integer *c, Integer &d) : a(0), b(Integer()), c(c), d(d) {
    std::cout << "IntegerAggregate::IntegerAggregate(" << a << ")" << std::endl;
}

// https://stackoverflow.com/a/6576135
IntegerAggregate::IntegerAggregate(const IntegerAggregate &obj) : a(obj.a), b(obj.b), c(obj.c), d(obj.d) {
    std::cout << "IntegerAggregate::IntegerAggregate(const IntegerAggregate &obj)" << std::endl;
}

IntegerAggregate::IntegerAggregate(IntegerAggregate &obj) : a(obj.a), b(obj.b), c(obj.c), d(obj.d){
    std::cout << "IntegerAggregate::IntegerAggregate(IntegerAggregate &obj)" << std::endl;
}
