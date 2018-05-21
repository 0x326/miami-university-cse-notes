#include <iostream>

#include "Rectangle.h"
#include "Square.h"
#include "SpecialRectangle.h"

int main(int argc, char *argv[]) {
    // Test Rectangle object
    std::cout << std::endl << "[main] (Entering block scope)" << std::endl;
    {
        std::cout << std::endl << "[main] Rectangle r{5, 5};" << std::endl;
        Rectangle r{5, 5};

        std::cout << std::endl << "[main] r.constMethod();" << std::endl;
        r.constMethod();

        std::cout << std::endl << "[main] r.constHiddenMethod();" << std::endl;
        r.constHiddenMethod();

        std::cout << std::endl << "[main] r.constOverriddenMethod();" << std::endl;
        r.constOverriddenMethod();

        std::cout << std::endl << "[main] r.constOverriddenMethodAnnotated();" << std::endl;
        r.constOverriddenMethodAnnotated();

        std::cout << std::endl << "[main] (Leaving block scope)" << std::endl;
    }

    // Test Square object
    std::cout << std::endl << "[main] (Entering block scope)" << std::endl;
    {
        std::cout << std::endl << "[main] Square s{5};" << std::endl;
        Square s{5};

        std::cout << std::endl << "[main] s.constMethod();" << std::endl;
        s.constMethod();

        std::cout << std::endl << "[main] s.constHiddenMethod();" << std::endl;
        s.constHiddenMethod();

        std::cout << std::endl << "[main] s.constOverriddenMethod();" << std::endl;
        s.constOverriddenMethod();

        std::cout << std::endl << "[main] s.constOverriddenMethodAnnotated();" << std::endl;
        s.constOverriddenMethodAnnotated();

        // Test polymorphism: Square is-a Rectangle
        std::cout << std::endl << "[main] Rectangle &sR = s;" << std::endl;
        Rectangle &sR = s;

        std::cout << std::endl << "[main] sR.constMethod();" << std::endl;
        sR.constMethod();

        std::cout << std::endl << "[main] sR.constHiddenMethod();" << std::endl;
        sR.constHiddenMethod();

        std::cout << std::endl << "[main] sR.constOverriddenMethod();" << std::endl;
        sR.constOverriddenMethod();

        std::cout << std::endl << "[main] sR.constOverriddenMethodAnnotated();" << std::endl;
        sR.constOverriddenMethodAnnotated();

        std::cout << std::endl << "[main] (Leaving block scope)" << std::endl;
    }

    // Test SpecialRectangle object

    std::cout << std::endl << "[main] SpecialRectangle specialRect{5, 5};" << std::endl;
    SpecialRectangle specialRect{5, 5};

    std::cout << std::endl << "[main] specialRect.accessSuperClassMethods();" << std::endl;
    specialRect.accessSuperClassMethods();

    std::cout << std::endl << "[main] (Leaving scope)" << std::endl;
}
