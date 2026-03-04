#include<iostream>
#include<vector>
using namespace std;
class Vector{
    public:
        vector<int> v;

        friend Vector operator*(const Vector& lhs, const Vector& rhs){
            Vector res;
            if(lhs.v.size()!=rhs.v.size()){
                cout << "error";
                return res;
            }
            size_t n = lhs.v.size();
            res.v.reserve(n);
            for(int i = 0 ; i < n ; i++){
                res.v.push_back(lhs.v[i]*rhs.v[i]);
            }
            return res;
            }
};



int main(){
    Vector a,b;
    a.v={1,2,3};
    b.v={4,5,6};
    Vector c = a * b;
    for(int i : c.v){
        cout << i << " ";
    }
    return 0;
}