#include <iostream>
#include <map>

int main(){
    std::map<int, int> map {{1, 2}, {3, 4}};
    // note that dereferencing a std::map::iterator returns a std::pair
    
    auto iter = map.begin();  // what is *iter?
    auto& pair = *iter;
    std::cout << "First element: key=" << pair.first << ", value=" << pair.second << std::endl;
    
    ++iter; // what is (*iter).second now?
    std::cout << "(*iter).second = " << (*iter).second << std::endl; 
    
    auto iter2 = iter;
    ++iter; // what does (*iter).first return? (now at end)
    if (iter != map.end()) {
        std::cout << "(*iter).first = " << (*iter).first << std::endl; 
    } else {
        std::cout << "iter reached map.end()" << std::endl;
    }
    
    return 0;
}

