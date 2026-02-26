#include <iostream>
#include <vector>
#include <string>
using namespace std;
struct Time {
    int hour, minute;
};
struct Course {
    std::string code;
    std::pair<Time, Time> time;
    std::vector<std::string> instructors;
};


void shift(vector<Course>& courses) { //会拷贝原来的vector，修改这个副本，不会影响原来的vector
    for (auto& course : courses){
        course.time.first.hour +=1;
        course.time.second.hour +=1;
    }
    for (size_t i=0;i<courses.size();i++){
        auto& [code,time,instructors]=courses[i];
        time.first.hour +=1;
        time.second.hour +=1;
    }
}

int main(){

    Course now{"CS106L", { {14, 30}, {15, 50} }, {"Raghuraman", "Chi"} };
    vector<Course> courses = {{"CS106A", {{10, 0}, {11, 20}}, {"Raghuraman"}}};
    shift(courses);
    cout << courses[0].code << " " << courses[0].time.first.hour << ":" << courses[0].time.first.minute
         << " - " << courses[0].time.second.hour << ":" << courses[0].time.second.minute
         << " Instructors: " << courses[0].instructors[0] << endl;



}
