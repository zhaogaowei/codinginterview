#include <iostream>
#include <vector>

using namespace std;

class A{
private:
	int n1;
	int n2;
public:
	A():n2(1),n1(n2+2){}
	void print() {
		cout << n1 << " " << n2 << endl;
	}
};
void mergeSort(vector<int> &v,int begin,int end) {
	if (begin == end)
		return;
	int mid = (begin + end) / 2;
	mergeSort(v, begin, mid);
	mergeSort(v, mid + 1, end);
	vector<int> temp;
	int i = begin;
	int j = mid + 1;
	while (i<=mid&&j<=end)
	{
		if (v[i] > v[j])
			temp.push_back(v[j++]);
		else
			temp.push_back(v[i++]);
	}
	for (; i <= mid; ++i)
		temp.push_back(v[i]);
	for (; j <= end; ++j)
		temp.push_back(v[j]);
	for (int i = 0; i < temp.size(); ++i) {
		v[begin + i] = temp[i];
	}
}
int main() {
	/*vector<int> v = { 9,1,4,3,2,5,8,7,6 };
	mergeSort(v, 0, v.size() - 1);
	for (auto i : v)
		cout << i << "\t";*/
	A a;
	a.print();
	return 0;
}