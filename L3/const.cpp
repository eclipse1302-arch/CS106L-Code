#include<iostream>
#include<vector>
using namespace std;
int main(){
    std::vector<int> vec{1, 2, 3};
    const std::vector<int> c_vec{7, 8};  // a const variable 无法修改
    std::vector<int>& ref = vec;         // a regular reference
    const std::vector<int>& c_ref = vec;  // a const reference
    vec.push_back(3);    // OKAY
    ref.push_back(3);   // OKAY
    const std::vector<int> c_vec{7, 8};  // a const variable
    // BAD - can't declare non-const ref to const vector
    //std::vector<int>& bad_ref = c_vec; // ERROR: cannot bind non-const lvalue reference of type ‘std::vector<int>&’ to an rvalue of type ‘std::vector<int>’

    return 0;

}
