#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int FindGreatestSumOfSubArray(vector<int> array) {
	if (!array.size())
		return 0;
	int curSum = array[0];
	int sum = array[0];
	for (int i = 1; i < array.size(); ++i) {
		if (curSum <= 0)
			curSum = array[i];
		else
			curSum += array[i];
		if (curSum > sum)
			sum = curSum;
	}
	return sum;
}
int FindGreatestSumOfSubArray1(vector<int> array) {
	vector<int> v(array.size(), 0);
	v[0] = array[0];
	int m = array[0];
	for (int i = 1; i < array.size(); ++i) {
		if (v[i - 1] < 0)
			v[i] = array[i];
		else
			v[i] = v[i-1] + array[i];
		m = max(v[i], m);
	}
	return  m;
}
int main() {
	vector<int> v = { 1,-2,3,10,-4,7,2,-5 };
	cout << FindGreatestSumOfSubArray1(v);
	return 0;
}