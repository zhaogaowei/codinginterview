#include <iostream>
#include <map>

using namespace std;

bool duplicate1(int numbers[], int length, int* duplication) {
	if (!numbers || length <= 0)
		return false;
	map<int,int> m;
	for (int i = 0; i < length; i++) {
		m[numbers[i]]++;
		if (m[numbers[i]] > 1) {
			*duplication = numbers[i];
			return true;
		}
	}
	return false;
}
bool duplicate(int numbers[], int length, int* duplication) {
	if (!numbers || length <= 0)
		return false;
	for (int i = 0; i < length;) {
		if (numbers[i] != i && numbers[i] == numbers[numbers[i]]) {
			*duplication = numbers[i];
			return true;
		}
		if (numbers[i] != i)
			swap(numbers[i], numbers[numbers[i]]);
		else
			i++;
	}
	return false;
}
int main() {
	int a[7] = { 2,3,1,0,2,5,3 };
	int ans;
	if (duplicate(a, 7, &ans))
		cout << ans << endl;
	else
		cout << "no" << endl;
	return 0;
}