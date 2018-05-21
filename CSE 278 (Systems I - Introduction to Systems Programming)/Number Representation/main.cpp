#include <iostream>
#include <iomanip>

int main(int argc, char *argv[]) {
    int someNumber = 255;
    std::cout << "Default: " << someNumber << std::endl;

    // Tell ``std::cout`` to format all future ``int``s as a hexadecimal
    // This stream manipulator can be inserted anytime and persists until explicitly reset
    std::cout << std::hex;

    std::cout << "Hexadecimal: 0x" << someNumber << std::endl;

    // Can pass a formatter during a print statement
    std::cout << "Octal: 0" << std::oct << someNumber << std::endl;

    std::cout << "Decimal: " << std::dec << someNumber << std::endl;
}
