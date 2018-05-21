#ifndef CSE_278_INTEGER_H
#define CSE_278_INTEGER_H

#include <iostream>

class Integer {
    // Since this function is not part of the class, it doesn't need to be declared as public
    friend std::ostream &operator<<(std::ostream &os, const Integer &obj);

    int x;

 public:
    Integer(int x = 0);

    bool operator<(const Integer &obj);
};


#endif //CSE_278_INTEGER_H
