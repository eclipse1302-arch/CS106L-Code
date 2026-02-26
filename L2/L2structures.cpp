#include<iostream>
#include<vector>
using namespace std;

struct Student{
    string name;
    string state;
    int age;
};

void print_student(const Student& s){
    cout << s.name << " from " << s.state << " is " << s.age << " years old." << endl;
}
int main(){
    Student s; //Method 1: Declare a global variable of type Student
    s.name = "Anna";
    s.state = "NY";
    s.age = 20;
    Student stu = {"Ethan", "CA", 30}; //Method 2: Declare and initialize a Student variable in one line
    print_student(s);
    print_student(stu);
    return 0;
}
