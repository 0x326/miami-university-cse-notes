#ifndef SQUARE_H
#define SQUARE_H

#include "Rectangle.h"

class Square : public Rectangle {
 public:
    Square(int sideLength);
    ~Square();
    int constHiddenMethod() const;
    int constOverriddenMethod() const;
    // The override annotation raises a compiler error if the following method
    // does not actually override a method of the superclass
    int constOverriddenMethodAnnotated() const override;
 private:
    int sideLength;
};

#endif //SQUARE_H
