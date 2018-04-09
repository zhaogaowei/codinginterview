#include <iostream>
#include <vector>

using namespace std;

int GetNumberOfK1(vector<int> data, int k) {
	int ans = 0;
	if (!data.size())
		return ans;
	for (int i = 0; i < data.size(); ++i) {
		if (data[i] == k)
			ans++;
	}
	return ans;
}
int getFirstK(vector<int> &data, int k, int begin, int end) {
	if (begin > end)
		return -1;
	int mid = (begin + end) / 2;
	if (data[mid] == k) {
		if (mid == 0 || (mid > 0 && data[mid - 1] != k))
			return mid;
		else
			end = mid - 1;
	}
	else if (data[mid] > k) {
		end = mid - 1;
	}
	else
	{
		begin = mid + 1;
	}
	return getFirstK(data, k, begin, end);
}
int getLastK(vector<int> &data, int k, int begin, int end) {
	if (begin > end)
		return -1;
	int mid = (begin + end) / 2;
	if (data[mid] == k) {
		if (mid == data.size() - 1 || (mid < data.size() - 1 && data[mid + 1] != k))
			return mid;
		else
			begin = mid + 1;
	}
	else if (data[mid] > k)
		end = mid - 1;
	else
		begin = mid + 1;
	return getLastK(data, k, begin, end);
}
int GetNumberOfK(vector<int> data, int k) {
	int number = 0;
	if (data.size()) {
		int first = getFirstK(data, k, 0, data.size() - 1);
		int last = getLastK(data, k, 0, data.size() - 1);
		if (first != -1 && last != -1)
			number = last - first + 1;
	}
	return number;
}
int main() {
	vector<int> v = { 1,2,3,3,3,3,3,4,5 };
	cout << GetNumberOfK(v, 3);
	return 0;
}