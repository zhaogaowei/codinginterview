#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool IsContinuous(vector<int> numbers) {
	if (numbers.size() != 5)
		return false;
	for (int i = 0; i < numbers.size(); ++i)
		if (numbers[i] < 0 || numbers[i]>13)
			return false;
	sort(numbers.begin(), numbers.end());
	int n0 = count(numbers.begin(),numbers.end(),0);
	if (n0 > 4)
		return false;
	int sum = 0;
	for (int i = n0; i < 4;i++) {
		sum += numbers[i + 1] - numbers[i]-1;
	}
	if (sum == 0 || sum == n0)
		return true;
	else
		return false;
}
int main() {
	vector<int> v = { 0,2,3,4,6 };
	cout << IsContinuous(v) << endl;
	return 0;
}