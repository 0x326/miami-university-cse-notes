#include <iostream>
#include <limits>

// Every function must be declared before it is used (e.g. declared on line 7 before use on line 51)
// If not for this line, ``add`` would be declared after it is used in main.
// Both are acceptable; only one is required
int add(int, int);
int add(int a, int b);
// A third option would be to write ``add``s definition here and avoid using the above statements

int main(int argc, char *argv[]) {
    int intMin = std::numeric_limits<int>::min();
    int intMax = std::numeric_limits<int>::max();
    int x = 5;
    int y = 2;

    /// Unary operators
    // Negation (-)
    -intMax == -intMax;
    -intMin == intMin;
    -0 == 0;

    /// Binary operators
    // Addition (+)/Subtraction (-)
    // No exceptions for integer overflows
    intMax + 1 == intMin;
    intMin - 1 == intMax;

    // Multiplication (*)

    // Division (/)
    // Division by zero causes a low-level error which cannot be caught with an exception
    //   https://stackoverflow.com/a/23418909
    // Know to distinguish between integer and floating-point division

    // Modulus (%)
    // Modulus by zero causes a low-level error which cannot be caught with an exception
    //   https://stackoverflow.com/a/23418909
    x % y == x % y;
    x % -y == x % y;
    -x % y == -(x % y);
    -x % -y == -(x % y);

    /// Keywords
    // For loops can have multiple initializations and increment expressions
    for (int i = 0, j = 4; i != j; i++, j--) {
        std::cout << "i == " << i << std::endl;
        std::cout << "j == " << j << std::endl;
        std::cout << std::endl;
    }

    /// Functions
    int sum = add(1, 2);
    std::cout << "add(1, 2) == " << sum << std::endl;
}

int add(int a, int b) {
    int returnValue = a + b;
    std::cout << "add(" << a << ", " << b << ") => " << "(Undefined behavior)" << std::endl;
    // Forgotten return statements result in undefined behavior
    // See Wikipedia for more details
    // https://en.wikipedia.org/w/index.php?title=Undefined_behavior&oldid=816983033#Examples_in_C_and_C++
}
