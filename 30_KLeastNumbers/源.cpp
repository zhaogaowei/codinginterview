#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <functional>

using namespace std;
//class greater1 {
//public:
//	bool operator()(int a,int b){
//		return a > b;
//	}
//};
int partition(vector<int>&arr,int begin,int end)
{
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
vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
	vector<int> v;
	if (k > input.size())
		return v;
	sort(input.begin(), input.end());
	return vector<int> (input.begin(),input.begin()+k);
}
vector<int> GetLeastNumbers_Solution1(vector<int> input, int k) {
	multiset<int> ms(input.begin(),input.end());
	vector<int> v;
	int j = 0;
	for (auto i = ms.begin(); i != ms.end()&&j<4; ++i,++j)
		v.push_back(*i);
	return v;
}
vector<int> GetLeastNumbers_Solution2(vector<int> input, int k) {
	int index = partition(input,0,input.size()-1);
	int begin = 0;
	int end = input.size() - 1;
	while (index != k-1)
	{
		if (index < k) {
			begin = index + 1;
			index = partition(input, begin, end);
		}
		else
		{
			end = index - 1;
			index = partition(input, begin, end);
		}
	}
	vector<int> v;
	for (int i = 0; i < k; ++i)
		v.push_back(input[i]);
	return v;
}
int main() {
	vector<int> input = { 4,5,1,6,2,7,3,8 };
	vector<int> output = GetLeastNumbers_Solution2(input, 6);
	multiset<int, greater<int>> m;
	for (int x : output)
		cout << x << " ";
	return 0;
}