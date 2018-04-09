#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool bigger(int a, int b) {
	int a1=0, a2=9, b1=0, b2=9;
	while (a) {
		a1 = a1 > a % 10 ? a1 : a % 10;
		a2 = a2 < a % 10 ? a2 : a % 10;
		a /= 10;
	}
	while (b)
	{
		b1 = b1 > b % 10 ? b1 : b % 10;
		b2 = b2 < b % 10 ? b2 : b % 10;
		b /= 10;
	}
	if (a2 < b2)
		return true;
	else if (a2 == b2&&a1 < b1)
		return true;
	else
		return false;
}
string PrintMinNumber(vector<int> numbers) {
	sort(numbers.begin(), numbers.end(), bigger);
	for (auto i : numbers)
		cout << i << "\t";
	string s;
	
	for (int i = 0; i < numbers.size(); ++i) {
		s.append(to_string(numbers[i]));
	}
	return s;
}

int main() {
	vector<int> v = { 5,10,55,99 };
	cout << PrintMinNumber(v) << endl;
	return 0;
}