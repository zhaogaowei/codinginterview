#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;

vector<int> big, little;
void Insert(int num)
{
	if (((big.size() + little.size()) & 1) == 1) {//even -> max_heap
		if (little.size() && num > little[0]) { 
			little.push_back(num);
			push_heap(little.begin(), little.end(),greater<int>());
			num = little[0];
			pop_heap(little.begin(), little.end(), greater<int>());
			little.pop_back();
		}
		big.push_back(num);
		push_heap(big.begin(), big.end(),less<int>());
	}
	else //odd -> little_heap
	{
		if (big.size() && num < big[0]) {
			big.push_back(num);
			push_heap(big.begin(), big.end(), less<int>());
			num = big[0];
			pop_heap(big.begin(), big.end(), less<int>());
			big.pop_back();
		}
		little.push_back(num);
		push_heap(little.begin(), little.end(), greater<int>());
	}
}

double GetMedian()
{
	if (((big.size() + little.size()) & 1) == 0)
		return (double)(big[0] + little[0]) / 2;
	else
		return little[0];
}
int main() {
	Insert(5);
	cout << GetMedian() << endl;
	Insert(2);
	cout << GetMedian() << endl;
	Insert(3); 
	cout << GetMedian() << endl;
	Insert(4); 
	cout << GetMedian() << endl;
	Insert(1);
	cout << GetMedian() << endl;
	Insert(6);
	cout << GetMedian() << endl;
	Insert(7); 
	cout << GetMedian() << endl;
	Insert(0);
	cout << GetMedian() << endl;
	Insert(8);
	cout << GetMedian() << endl;
	return 0;
}