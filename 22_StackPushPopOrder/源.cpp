#include <iostream>
#include <vector>
#include <stack>

using namespace std;

bool IsPopOrder(vector<int> pushV, vector<int> popV) {
	if (!pushV.size() || !popV.size() || pushV.size() != popV.size())
		return false;
	else {
		stack<int> s;
		for (int i = 0, j = 0; i < pushV.size(); ++i) {
			s.push(pushV[i]);
			while (!s.empty() && s.top() == popV[j]) {
				s.pop();
				j++;
			}
		}
		return s.empty();
	}
}
int main() {
	vector<int> v1 = { 1,2,3,4,5 };
	vector<int> v2 = { 4,5,3,1,2 };
	cout << IsPopOrder(v1, v2);
	return 0;
}