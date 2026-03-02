#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;
int main(){
    std::set<int> myset {3, 1, 4, 1, 5, 9};
    for (auto it = myset.begin(); it != myset.end(); ++it) {
        // dereference iterator to get element
        const auto& elem = *it;
        cout << elem << endl;
    }
        for (const auto& elem : myset) {
        // dereference iterator to get element
        cout << elem << endl;
    }

    // map requires two template parameters: key and value
    std::map<int,int> mymap {{1, 6}, {1, 8}, {0, 3}, {3, 9}};
    for (auto it = mymap.begin(); it != mymap.end() ; ++it) {
        const auto& [key, value] = *it; // structured binding!
        cout << key << ":" << value << endl;
    }
/*     Exercise: print all elements in these collections
    Fill in the blanks in chat! Should be the same for set/map. */
    return 0;


}

