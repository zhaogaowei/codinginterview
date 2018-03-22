#include <iostream>
#include <string>

using namespace std;

bool Increment(string &number) {
	bool isOverflow = false;
	int nTakeOver = 0;
	for (size_t i = number.length() - 1; i >= 0; --i) {
		int nSum = number[i] - '0' + nTakeOver;
		if (i == number.length() - 1)
			nSum++;
		if (nSum >= 10) {
			if (i == 0) {
				isOverflow = true;
				break;
			}
			else
			{
				nSum -= 10;
				nTakeOver = 1;
				number[i] = nSum + '0';
			}
		}
		else
		{
			number[i] = nSum + '0';
			break;
		}
	}
	return isOverflow;
}
void PrintNumber(string number) {
	int index = 0;
	for (size_t i = 0; i < number.length(); ++i) {
		if (number[i] != '0') {
			index = i;
			break;
		}
	}
	for (size_t i = index; i < number.length(); ++i)
		cout << number[i];
	cout << '\t';
}
void print1ToMaxOfNDigits(int n) {
	if (n < 0)
		return;
	string number(n, '0');
	while (!Increment(number)) {
		PrintNumber(number);
	}
}
void printNext(string &number, int length, int index) {
	if (index == length - 1) {
		PrintNumber(number);
		return;
	}
	for (size_t i = 0; i < 10; ++i) {
		number[index + 1] = i + '0';
		printNext(number, length, index + 1);
	}
}
void print1ToMaxOfNDigits1(int n) {
	if (n < 0)
		return;
	string number(n, '0');
	for (size_t i = 0; i < 10; i++) {
		number[0] = i + '0';
		printNext(number, n, 0);
	}
}
int main() {
	print1ToMaxOfNDigits1(2);
	return 0;
}