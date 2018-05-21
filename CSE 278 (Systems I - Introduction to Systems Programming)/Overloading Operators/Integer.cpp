#include "Integer.h"

Integer::Integer(int x) : x(x) {
    std::cout << "Integer::Integer(" << x << ")" << std::endl;
}

std::ostream &operator<<(std::ostream &os, const Integer &obj) {
    os << "Integer(" << obj.x << ")";
    return os;
}

bool Integer::operator<(const Integer &obj) {
    bool returnValue = this->x < obj.x;
    std::cout << "Integer::operator<(const Integer &obj) => " << returnValue << std::endl;
    return returnValue;
}
