#include <iostream>
#include <vector>

using namespace std;

vector<int> multiply(const vector<int>& A) {
	vector<int> v(A.size(),1);
	for (int i = 0; i < A.size(); ++i) {
		for (int j = 0; j < A.size(); ++j) {
			if (j != i)
				v[i] *= A[j];
		}
	}
	return v;
}
vector<int> multiply1(const vector<int>& A) {
	vector<int> v;
	vector<int> b1(A.size(), 1);
	vector<int> b2(A.size(), 1);
	for (int i = 1; i < A.size(); ++i) {
		b1[i] = b1[i - 1] * A[i - 1];
	}
	for (int i = A.size() - 2; i >= 0; i--) {
		b2[i] = b2[i + 1] * A[i + 1];
	}
	for (int i = 0; i < A.size(); ++i)
		v.push_back(b1[i] * b2[i]);
	return v;
}
int main() {
	vector<int> v = { 1,2,3,4,5 };
	vector<int> ans = multiply1(v);
	for (auto x : ans)
		cout << x << " ";
	return 0;
}