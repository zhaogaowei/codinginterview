#include <iostream>
#include <vector>

using namespace std;

int InversePairs(vector<int> data) {
	int ans = 0;
	for (int i = 0; i < data.size()-1; ++i) {
		for (int j = i + 1; j < data.size(); ++j) {
			if (data[i] > data[j])
				ans++;
		}
	}
	return ans;
}
long long core(vector<int> &data, vector<int> &copy,int begin,int end) {
	if (end == begin)
	{
		copy[begin] = data[begin];
		return 0;
	}
	int len = (end-begin) / 2;
	long long left = core(data, copy, begin, begin+len);
	long long right = core(data, copy, begin + len + 1, end);
	int i = begin + len;
	int j = end;
	long long count = 0;
	int copyIndex = end;
	while (i >= begin && j >= begin + len + 1) {
		if (data[i] > data[j]) {
			copy[copyIndex--] = data[i--];
			count = count + j - begin - len;
			cout << count << " ";
		}
		else
		{
			copy[copyIndex--] = data[j--];
		}
	}
	for (; i >= begin; --i)
		copy[copyIndex--] = data[i];
	for (; j >= begin + len + 1; --j)
		copy[copyIndex--] = data[j];
	//cout << left << " " << right << " " << count << endl;
	return left + right + count;
}
//long long core(vector<int> &data, vector<int> &copy, int start, int end)
//{
//	if (start == end)
//	{
//		copy[start] = data[start];
//		return 0;
//	}
//	int length = (end - start) / 2;
//	long long left = core(copy, data, start, start + length)% 1000000007;
//	long long right = core(copy, data, start + length + 1, end) % 1000000007;
//
//	int i = start + length;
//	int j = end;
//	int indexcopy = end;
//	long long count = 0;
//	while (i >= start&&j >= start + length + 1)
//	{
//		if (data[i]>data[j])
//		{
//			copy[indexcopy--] = data[i--];
//			count = count + j - start - length;  
//		}
//		else
//		{
//			copy[indexcopy--] = data[j--];
//		}
//	}
//	for (; i >= start; i--)
//		copy[indexcopy--] = data[i];
//	for (; j >= start + length + 1; j--)
//		copy[indexcopy--] = data[j];
//	return (left + right + count % 1000000007) % 1000000007;
//}
int InversePairs1(vector<int> data) {
	vector<int> copy(data);
	int count = core(data, copy,0,data.size()-1);
	return count;
}
int main() {
	vector<int> v = { 7,5,6,4 };
	cout << InversePairs1(v) << endl;
	return 0;
}