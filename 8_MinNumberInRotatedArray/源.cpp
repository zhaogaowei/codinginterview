#include <iostream>
#include <vector>

using namespace std;

int minNumberInRotateArray(vector<int> v) {
	if (v.size() == 0)
		throw new exception("empty vector!\n");
	int start = 0, end = v.size() - 1, mid;
	mid = start;
	if (v[start] < v[end])
		return v[start];
	while (v[start] >= v[end])
	{
		if (end - start == 1)
		{
			mid = end;
			break;
		}
		mid = (start + end) / 2;
		if (v[mid] >= v[start])
			start = mid;
		else if(v[mid] <= v[end])
			end = mid;
	}
	return v[mid];
}

int main() {
	vector<int> v = { 6,7,8,9,1,2,3 };
	cout << minNumberInRotateArray(v)<< endl;
	cin.get();
	return 0;
}