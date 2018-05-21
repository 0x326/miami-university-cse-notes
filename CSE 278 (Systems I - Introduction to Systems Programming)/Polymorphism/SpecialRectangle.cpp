#include <iostream>
#include "SpecialRectangle.h"

// Constructor arguments go to subclass constructor and default super constructor is used implicitly
SpecialRectangle::SpecialRectangle(int height, int width) {
    std::cout << "SpecialRectangle::SpecialRectangle(" << height << ", " <<
        width << ")" << std::endl;
}

void SpecialRectangle::accessSuperClassMethods() const {
    std::cout << "SpecialRectangle::accessSuperClassMethods()" << std::endl;

    this->constMethod();
};
