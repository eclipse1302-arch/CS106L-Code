#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

vector<string> split(const string& s, char delim) {
    vector<string> res;
    string token;
    istringstream iss(s);
    while (getline(iss, token, delim) && !token.empty()) res.push_back(token);
    return res;
}

string find(const vector<string>& vec, const string& target) {
    auto it = find(vec.begin(), vec.end(), target);
    if (it != vec.end()) return *it;
    return "";
}

int main() {
    string data = "a,b,c";
    vector<string> components = split(data, ',');
    for (const string& s : components) {
        cout << s << endl;
    }
    return 0;
}
