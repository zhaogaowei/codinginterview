#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isUgly(int number) {
	while (number % 2 == 0)
		number = number >> 1;
	while (number % 3 == 0)
		number /= 3;
	while (number % 5 == 0)
		number /= 5;
	return number == 1 ? true : false;
}
int GetUglyNumber_Solution(int index) {
	int i = 0;
	int start = 0;
	while (i<=index)
	{
		start++;
		if (isUgly(start)) {
			i++;
		}
	}
	return start;
}
int GetUglyNumber_Solution1(int index) {
	if (index < 7)
		return index;
	int t2 = 0, t3 = 0, t5 = 0;
	vector<int> v(index);
	v[0] = 1;
	for (int i = 1; i < index; ++i) {
		v[i] = min(v[t2] * 2, min(v[t3] * 3, v[t5] * 5));
		cout << v[i] << " ";
		if (v[i] == v[t2] * 2)
			t2++;
		if (v[i] == v[t3] * 3)
			t3++;
		if (v[i] == v[t5] * 5)
			t5++;
	}
	return v[index - 1];
}
int main() {
	cout << GetUglyNumber_Solution1(1500);
	return 0;
}