#include <iostream>
#include <vector>

using namespace std;

size_t findFirst1(int result) {
	size_t index = 32;
	for (int i = 1; i <= 32; i++) {
		if (result % 2) {
			index = i;
			break;
		}
		result = result >> 1;
	}
	return index;
}
bool is1(int number,size_t index) {
	number = number >> index-1;
	return number & 1;
}
void FindNumsAppearOnce(vector<int> data, int* num1, int *num2) {
	*num1 = 0;
	*num2 = 0;
	if (!data.size())
		return;
	int result = 0;
	for (int i = 0; i < data.size(); ++i)
		result ^= data[i];
	size_t index = findFirst1(result);
	vector<int> v1, v2;
	for (int i = 0; i < data.size(); ++i) {
		if (is1(data[i],index))
			*num1 ^=data[i];
		else
			*num2 ^= data[i];
	}
}
int main() {
	int num1, num2;
	vector<int> v = { 2,4,3,6,3,2,5,5 };
	FindNumsAppearOnce(v, &num1, &num2);
	cout << num1 << " " << num2 << endl;
	return 0;
}