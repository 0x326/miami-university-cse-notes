#include <iostream>
#include <vector>

int main() {
    std::vector<int> vector;

    std::cout << "Empty: " << vector.empty() << std::endl;
    for (auto i = 0; i < 5; i++) {
        std::cout << "Adding " << i << " to vector" << std::endl;
        vector.push_back(i);
    }
    std::cout << std::endl;

    std::cout << "Empty: " << vector.empty() << std::endl;
    std::cout << "Size: " << vector.size() << std::endl;
    std::cout << "Capacity: " << vector.capacity() << std::endl;
    std::cout << "Max size: " << vector.max_size() << std::endl;
    std::cout << std::endl;

    std::cout << "Resizing to 4" << std::endl;
    std::cout << "New size: " << vector.size() << std::endl;
    std::cout << "New capacity: " << vector.capacity() << std::endl;
    std::cout << "New max size: " << vector.max_size() << std::endl;
    std::cout << std::endl;

    std::cout << "Shrinking to fit" << std::endl;
    std::cout << "New size: " << vector.size() << std::endl;
    std::cout << "New capacity: " << vector.capacity() << std::endl;
    std::cout << "New max size: " << vector.max_size() << std::endl;
    std::cout << std::endl;

    std::cout << "Output of begin and end: ";
    for (auto i = vector.begin(); i != vector.end(); ++i) {
        std::cout << *i << " ";
    }
    // for (auto &i : vector) {
    //     std::cout << i << " ";
    // }
    std::cout << std::endl;

    std::cout << "Output of cbegin and cend: ";
    for (auto i = vector.cbegin(); i != vector.cend(); ++i) {
        std::cout << *i << " ";
    }
    // for (auto i : vector) {
    //     std::cout << i << " ";
    // }
    std::cout << std::endl;

    std::cout << "Output of rbegin and rend: ";
    for (auto ir = vector.rbegin(); ir != vector.rend(); ir++) {
    std::cout << std::endl;
        std::cout << *ir << " ";
    }
    std::cout << std::endl;

    std::cout << "\nOutput of crbegin and crend : ";
    for (auto ir = vector.crbegin(); ir != vector.crend(); ir++) {
        std::cout << *ir << " ";
    }
    std::cout << std::endl;

    return EXIT_SUCCESS;
}
