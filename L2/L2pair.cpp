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
Student lookupStudent() {
 Student s;
 s.name = "Ethan";
 s.state = "CA";
 s.age = 20;
 return s;
}
Student foundStudent = lookupStudent();

std::pair<bool, Student> lookupStudent(string name) {
 Student blank;
 if (notFound(name)) return std::make_pair(false, blank);
 Student result = getStudentWithName(name);
 return std::make_pair(true, result);
}
std::pair<bool, Student> output = lookupStudent("Keith");


int main(){
    std::pair<bool, Student> query_result;
    query_result.first = true;
    query_result.second = {"Ethan", "CA", 30};


    std::tuple<string, int, int> query_result;
    string name = std::get<0>(query_result);
    int num = std::get<1>(query_result);
    return 0;
}
