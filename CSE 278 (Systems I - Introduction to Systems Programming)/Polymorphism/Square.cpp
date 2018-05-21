#include <iostream>
#include "Square.h"

// ``: Rectangle(arg, arg)`` is a call to the super constructor that occurs before the body of this method
// It is optional provided Rectangle as a default constructor
Square::Square(int sideLength) : Rectangle(sideLength, sideLength) {
    std::cout << "Square::Square(" << sideLength << ")" << std::endl;
    this->sideLength = sideLength;
}

Square::~Square() {
    std::cout << "Square::~Square()" << std::endl;
}

int Square::constHiddenMethod() const {
    int returnValue = this->sideLength;
    std::cout << "Square::constHiddenMethod() => " << returnValue << std::endl;
    return returnValue;
}

int Square::constOverriddenMethod() const {
    int returnValue = this->sideLength * this->sideLength;
    std::cout << "Square::constOverriddenMethod() => " << returnValue << std::endl;
    return returnValue;
}

int Square::constOverriddenMethodAnnotated() const {
    int returnValue = 4 * this->sideLength;
    std::cout << "Square::constOverriddenMethodAnnotated() => " << returnValue << std::endl;
    return returnValue;
}
