#include <iostream>
#include <fstream>

int main(int argc, char *argv[]) {
    std::ifstream inFile{"filePath"};
    if (!inFile.good()) {
        std::cout << "Error opening input file" << std::endl;
    }

    std::ofstream outFile{"filePath"};
    if (!outFile.good()) {
        std::cout << "Error opening output file" << std::endl;
    }

    std::string word;
    while (inFile >> word) {
        // Do something with each word
        outFile << word;
    }

    // Files are closed by the destructor so we don't need to close them manually
    return 0;
}
