#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main() {
    vector<int> list_ini={3, 5};
    cout << list_ini.size() << " " << list_ini.capacity() << endl; // 2
    return 0;
}