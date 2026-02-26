#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Student {
    string name;
    string state;
    int age;
};

int main(){
    pair<int, string> p = {1, "hello"}; // make_pair 是一个工厂函数，创建一个 std::pair 对象
    std::pair<bool, int>
    some_pair = {false, 6};
    Student s = {"Ethan", "CA", 20};
    auto [a,b] = p;
    cout << a << " " << b << endl;
    cout << s.name << " " << s.state << " " << s.age << endl;
}