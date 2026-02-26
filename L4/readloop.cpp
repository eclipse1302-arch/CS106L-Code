#include <iostream>
#include <sstream>
#include <string>

void doSomething(const std::string &s) {
    std::cout << "Processed: " << s << std::endl;
}

int main() {
    std::string input = "one two three";
    std::istringstream stream(input);
    std::string temp;

    while (true) {
        stream >> temp; // read data
        if (stream.fail()) break; // checks for fail bit OR bad bit
        doSomething(temp);
    }

    std::cout << "Loop finished.\n";
    return 0;
}