#include<iostream>
#include<vector>
using namespace std;
int doubleValue(int x) {
    x *= 2;
    return x;
}
int doubleValue2(int& x) {
    x *= 2;
    return x;
}
int main() {
    int myValue = 5;
    int result = doubleValue(myValue);
    cout << myValue << endl; // 5 (unchanged because doubleValue takes a copy)
    cout << result << endl;  // 10
    int result2 = doubleValue2(myValue);
    cout << myValue << endl; // 10 (changed because doubleValue2 takes a reference)
    cout << result2 << endl; // 10


    std::vector<int> original{1, 2};
    std::vector<int> copy = original;//独立拷贝
    std::vector<int>& ref = original;//引用
    original.push_back(3);
    copy.push_back(4);
    ref.push_back(5);
    // original (and also ref!) = {1, 2, 3, 5}
    // copy = {1, 2, 4}
    ref = copy;
    copy.push_back(6);
    ref.push_back(7);

    cout << "original: ";
    for (int i : original) {
        cout << i << " ";
    }
    cout << endl;
    cout << "copy: ";
    for (int i : copy) {
        cout << i << " ";
    }
    cout << "ref: ";
    for (int i : ref) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}