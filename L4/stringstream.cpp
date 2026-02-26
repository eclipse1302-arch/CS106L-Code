#include <iostream>
#include <sstream>
#include <string>

int main() {
    std::string input = "5 seventy 2";
    std::istringstream i(input);
    int x;
    std::string y;
    int z;

    i >> x >> y >> z;
    std::cout << "x=" << x << " y='" << y << "' z=" << z << std::endl;
    std::cout << z << std::endl;
    return 0;
}
