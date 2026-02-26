#include<vector>
#include<deque>
#include<set>
#include<string>
#include<algorithm>
using namespace std;

template <typename It>
size_t my_distance(It first, It last){
  return last-first;
}

int main() {
  std::vector<std::string> names ={"Anna","Ethan","Nikhil","Avery"};

  auto anna_iter = find(names.begin(),names.end(),"Anna");
  auto avery_iter = find(names.begin(),names.end(),"Avery");
  return distance(anna_iter,avery_iter);
}