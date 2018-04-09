#include <iostream>
#include <vector>

using namespace std;

vector<int> FindContinuousSequence(vector<int> &v,int sum) {
	vector<int> two;
	if (!v.size())
		return two;
	for (int i = 0, j = v.size() - 1; i < j;) {
		if (v[i] + v[j] == sum) {
			two.push_back(v[i]);
			two.push_back(v[j]);
			break;
		}
		else if(v[i]+v[j]>sum)
		{
			j--;
		}
		else
		{
			i++;
		}
	}
	return two;
}
int main() {
	vector<int> v = { 1,2,4,7,11,15 };
	vector<int> ans = FindContinuousSequence(v, 15);
	for (int x : ans)
		cout << x << " ";
	return 0;
}