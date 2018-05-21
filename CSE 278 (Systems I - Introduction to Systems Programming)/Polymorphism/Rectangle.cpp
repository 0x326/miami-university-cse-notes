#include <iostream>
#include "Rectangle.h"

Rectangle::Rectangle() {
    std::cout << "Rectangle::Rectangle()" << std::endl;
    this->height = this->width = 0;
}

Rectangle::Rectangle(int height, int width) {
    std::cout << "Rectangle::Rectangle(" << height << ", " << width << ")" <<
        std::endl;
    this->height = height;
    this->width = width;
}

Rectangle::~Rectangle() {
    std::cout << "Rectangle::~Rectangle()" << std::endl;
}

int Rectangle::constMethod() const {
    int returnValue = this->width;
    std::cout << "Rectangle::constMethod() => " << returnValue << std::endl;
    return returnValue;
}

int Rectangle::constHiddenMethod() const {
    int returnValue = this->height;
    std::cout << "Rectangle::constHiddenMethod() => " << returnValue << std::endl;
    return returnValue;
}

int Rectangle::constOverriddenMethod() const {
    int returnValue = this->height * this->width;
    std::cout << "Rectangle::constOverriddenMethod() => " << returnValue << std::endl;
    return returnValue;
}

int Rectangle::constOverriddenMethodAnnotated() const {
    int returnValue = 2 * this->height + 2 * this->width;
    std::cout << "Rectangle::constOverriddenMethodAnnotated() => " << returnValue << std::endl;
    return returnValue;
}
