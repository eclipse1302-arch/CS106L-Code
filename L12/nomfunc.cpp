#include <iostream>
using namespace std;

class Person {
public:
    friend bool operator==(const Person& lhs, const Person& rhs);
private:
    int secretID = 0;
};

bool operator==(const Person& lhs, const Person& rhs) {
    return lhs.secretID == rhs.secretID;
}

class Time {
public:
    Time(int h = 0, int m = 0, int s = 0) : hour(h), minute(m), second(s) {}
    friend ostream& operator<<(ostream& out, const Time& time);
private:
    int hour, minute, second;
};

ostream& operator<<(ostream& out, const Time& time) {
    out << time.hour << ":" << time.minute << ":" << time.second;
    return out;
}

class Fraction {
public:
    friend Fraction operator*(const Fraction& lhs, const Fraction& rhs);
    friend ostream& operator<<(ostream& out, const Fraction& target);
private:
    int former, latter;
};

Fraction operator*(const Fraction& lhs, const Fraction& rhs) {
    Fraction result;
    result.former = lhs.former * rhs.former;
    result.latter = lhs.latter * rhs.latter;
    return result;
}

ostream& operator<<(ostream& out, const Fraction& target) {
    out << target.former << "/" << target.latter;
    return out;
}

int main() {
    Time t = {5, 22, 31};      // 注意：这里能用聚合初始化，因为 Time 没有自定义构造函数，且成员都可用
    cout << t << endl;
    return 0;
}