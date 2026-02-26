#include <iostream>
#include <vector>
#include <set>
using namespace std;
int main(){
    std::vector<int> vector{3, 1, 4, 1, 5, 9};
    for (size_t i=0; i < vector.size(); i++) {
        const auto& elem = vector[i];
        cout << elem << endl;
    }
    std::set<int> set{3, 1, 4, 1, 5, 9};
    for (size_t i : set) {
        const auto& elem = i;
        cout << elem << endl;
}
    return 0;

}
