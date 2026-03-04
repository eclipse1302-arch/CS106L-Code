#include <iostream>
#include <vector>
using namespace std;

class Vector {
public:
	vector<int> v;

	friend Vector operator*(const Vector& lhs, const Vector& rhs) {
		Vector res;
		size_t n = min(lhs.v.size(), rhs.v.size());
		res.v.reserve(n);
		for (size_t i = 0; i < n; i++) {
			res.v.push_back(lhs.v[i] * rhs.v[i]);
		}
		return res;
	}
};

int main() {
	Vector a, b;
	a.v = {1, 2, 3};
	b.v = {4, 5, 6};

	Vector c = a * b;   // 这样调用 operator*
	// 等价写法：Vector c = operator*(a, b);

	for (int x : c.v) cout << x << " ";
}