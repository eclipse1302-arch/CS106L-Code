#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int main() {
    auto p =make_pair("s", 5);
    auto [a, b]= p;
    cout << a << " " << b << endl;

    return 0;
}