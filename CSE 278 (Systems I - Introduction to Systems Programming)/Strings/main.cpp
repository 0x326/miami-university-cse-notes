#include <iostream>

int main(int argc, char *argv[]) {
    std::string input;
    std::cout << "Enter a line of text: ";
    getline(std::cin, input);

    std::cout << "input == \"" << input << "\"" << std::endl;
    std::cout << "input.size() == " << input.size() << std::endl;
    std::cout << "input[0] == '" << input[0] << "'" << std::endl;
    std::cout << "input[input.size() - 1] == '" << input[input.size() - 1] << "'" << std::endl;

    // If not found, ``find`` returns std::string::npos
    // It is the maximum value representable in a std::string::size_type variable
    // It is an unsigned value and, when converted to a signed value, is equal to -1.
    std::cout << "input.find(\" \") == " << input.find(" ") << std::endl;
    std::cout << "input.rfind(\" \") == " << input.rfind(" ") << std::endl;
    // If finding a single character, it is better to use the character type
    std::cout << "input.find(' ') == " << input.find(' ') << std::endl;
    std::cout << "input.rfind(' ') == " << input.rfind(' ') << std::endl;

    // [inclusive, exclusive)
    std::cout << "input.substr(0, 5) == \"" << input.substr(0, 5) << "\"" << std::endl;

    // Strings can also be treated like streams (requires ``#include <sstream>``)
    // See https://stackoverflow.com/a/20595061
}
