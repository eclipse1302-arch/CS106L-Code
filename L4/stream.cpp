#include <iostream>
#include <fstream>
#include <string>

int main() {
    // create a sample file we will read from
    const char *filename = "sample.txt";
    {
        std::ofstream ofs(filename);
        ofs << "Hello, world!\nThis is a test.\n";
    }

    std::ifstream input;

    // open() opens the stream on a file
    input.open(filename);
    if (!input) {
        std::cerr << "Failed to open " << filename << "\n";
        return 1;
    }
    std::cout << "Opened " << filename << " successfully." << std::endl;

    // read a single char using get()
    char ch;
    input.get(ch);  // reads a single character
    std::cout << "First character read with get(): '" << ch << "'\n";

    // read until EOF to trigger failbit
    while (input.get(ch)) {
        // print remaining chars
        std::cout << ch;
    }
    std::cout << "\nReached end of file." << std::endl;

    // when we try to read past EOF, failbit is set
    if (input.fail()) {
        std::cout << "failbit is set after reading past EOF." << std::endl;
    }

    // clear() resets the stream state (clear failbit, eofbit, etc.)
    input.clear();
    std::cout << "After clear(): good() = " << input.good() << std::endl;

    // seekg() to reposition the get pointer back to beginning
    input.seekg(0);
    std::cout << "After seekg(0), reading again:" << std::endl;
    while (input.get(ch)) {
        std::cout << ch;
    }
    std::cout << std::endl;

    input.close();
    std::cout << "Stream closed." << std::endl;
    return 0;
}
