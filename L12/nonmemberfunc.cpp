#include<iostream>
using namespace std;
class Person{
    public:
        friend bool operator==(const Person& lhs, const Person& rhs);
        int secretID;
};
class Time{
    public:
        friend std::ostream& operator<<(std::ostream& out, const Time& time);
        int hour,minute,second;
};
bool operator==(const Person& lhs, const Person& rhs){
    return (lhs.secretID == rhs.secretID);
}


class Fraction{
    public:
        friend Fraction operator*(const Fraction& lhs, const Fraction& rhs);
        friend std::ostream& operator<<(std::ostream& out, const Fraction& target);
    private:
        int former,latter;
};

Fraction operator*(const Fraction& lhs, const Fraction& rhs) {
    Fraction result;
    result.former = lhs.former * rhs.former;
    result.latter = lhs.latter * rhs.latter;
    return result;
}

ostream& operator<<(ostream& out, const Time& time){
    out << time.hour << ":" << time.minute << ":" << time.second << std::endl;
    return out;
}

int main(){
    Time t(5,22,31);
    cout << t << endl;
    return 0;
}