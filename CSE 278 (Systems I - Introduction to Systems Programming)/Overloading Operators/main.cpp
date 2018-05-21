// https://stackoverflow.com/a/4421719

#include <iostream>
#include <iomanip>
#include "Integer.h"

int main(int argc, char *argv[]) {
    // Print bool values as "true" and "false" instead of 1 and 0
    std::cout << std::boolalpha;

    Integer x1, x2 = 3;
    std::cout << "x1 == " << x1 << std::endl;
    std::cout << "x2 == " << x2 << std::endl;

    std::cout << "x1 < x2 == " << (x1 < x2) << std::endl;
    std::cout << "x2 < x1 == " << (x2 < x1) << std::endl;
}
