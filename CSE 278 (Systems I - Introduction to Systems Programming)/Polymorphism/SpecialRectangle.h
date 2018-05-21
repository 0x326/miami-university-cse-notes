#ifndef SPECIAL_RECTANGLE_H
#define SPECIAL_RECTANGLE_H

#include "Rectangle.h"

// class subClass : specifier SuperClass
// ``specifier`` restrains the inherited specifiers and ensures they are at most ``specifier``
// See https://stackoverflow.com/a/1372858 for more info
class SpecialRectangle : private Rectangle {
 public:
    SpecialRectangle(int height, int width);
    void accessSuperClassMethods() const;

 private:
};

#endif //SPECIAL_RECTANGLE_H
