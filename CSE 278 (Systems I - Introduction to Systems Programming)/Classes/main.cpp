// #include <file> includes a system file
// #include "file" includes a local file
#include <iostream>
#include "IntegerAggregate.h"

int main() {
    Integer b{1};  // uniform initialization (as of C++11)
    Integer *c = &b;
    Integer &d = b;

    std::cout << std::endl << "[main] IntegerAggregate foo{c, d};" << std::endl;
    IntegerAggregate foo{c, d};

    std::cout << std::endl << "[main] IntegerAggregate bar = foo;" << std::endl;
    IntegerAggregate bar = foo;

    std::cout << std::endl;

    // Change values in ``foo``
    foo.a++;
    foo.b.i++;
    foo.c->i++;
    foo.d.i++;

    // Compare values to ``bar``
    std::cout << "foo.a == " << foo.a << std::endl;
    std::cout << "bar.a == " << bar.a << std::endl;
    std::cout << std::endl;

    std::cout << "foo.b.i == " << foo.b.i << std::endl;
    std::cout << "bar.b.i == " << bar.b.i << std::endl;
    std::cout << std::endl;

    // Note: ``foo.c`` and ``bar.c`` point to the same memory location
    std::cout << "foo.c->i == " << foo.c->i << std::endl;
    std::cout << "bar.c->i == " << bar.c->i << std::endl;
    std::cout << "(foo.c == bar.c) == " << (foo.c == bar.c) << std::endl;
    std::cout << std::endl;

    // Note: ``foo.d`` and ``bar.d`` point to the same memory location
    std::cout << "foo.d.i == " << foo.d.i << std::endl;
    std::cout << "bar.d.i == " << bar.d.i << std::endl;
    std::cout << std::endl;

    // Compare to locally-scoped Integer
    std::cout << "b.i == " << b.i << std::endl;
    std::cout << "c->i == " << c->i << std::endl;
    std::cout << "d.i == " << d.i << std::endl;
}
