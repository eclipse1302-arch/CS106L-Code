#include<iostream>
#include<fstream>
int main() {
    std::cout << 5 << std::endl; // prints 5 to the console
    std::ofstream out("out.txt", std::ofstream::out);
    out << 5 << std::endl; // writes 5 to out.txt
    out.close();
    std::ifstream in("out.txt", std::ifstream::in);
    int value;
    in >> value; // reads the value from out.txt into the variable 'value'
    std::cout << value << std::endl; // prints the value read from the file
    in.close();
    return 0;
}