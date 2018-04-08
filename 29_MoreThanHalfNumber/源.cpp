#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int MoreThanHalfNum_Solution(vector<int> numbers) {
	map<int,int> m;
	int ans=0;
	for (int i = 0; i < numbers.size(); ++i) {
		m[numbers[i]]++;
		if (m[numbers[i]] > (numbers.size() >> 1)) {
			ans = numbers[i];
			break;
		}
	}
	return ans;
}
void partition(vector<int> &v)
{
	int x = v[0];
	int l = 0;
	for (int i = 1; i < v.size(); ++i) {
		if (v[i] <= x) {
			l++;
			if (l != i)
				swap(v[l], v[i]);
		}
	}
	swap(v[0], v[l]);
}

int partition1(vector<int>&arr)
{
	int begin = 0;
	int end = arr.size() - 1;
	int pivot = arr[begin];
	while (begin < end)
	{
		while (begin < end && arr[end] >= pivot) --end;
		arr[begin] = arr[end];
		while (begin < end && arr[begin] <= pivot) ++begin;
		arr[end] = arr[begin];
	}
	arr[begin] = pivot;
	return begin;
}
int main() {
	vector<int> v = { 1,2,3,2,2,2,5,4,2 };
	partition1(v);
	for (auto i : v)
		cout << i << " ";
	cout << endl;
	cout << v[v.size() / 2] << endl;
	cout << MoreThanHalfNum_Solution(v) << endl;
	return 0;
}