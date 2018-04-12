#include <iostream>
#include <vector>

using namespace std;

vector<int> maxInWindows(const vector<int>& num, unsigned int size)
{
	vector<int> ans;
	if (num.size() == 0 || size <= 0)
		return ans;
	for (int i = 0; i < num.size() - size + 1; i++) {
		int f = INT_MIN;
		for (int j = 0; j < size; j++) {
			if (num[i + j] > f)
				f = num[i + j];
		}
		ans.push_back(f);
	}
	return ans;
}
int main() {
	vector<int> v = { 2,3,4,2,6,2,5,1 };
	vector<int> ans = maxInWindows(v, 3);
	for (int x : ans)
		cout << x << " ";
	return 0;
}