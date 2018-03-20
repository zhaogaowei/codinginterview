#include <iostream>

using namespace std;

int  NumberOf1(int n) {
	int count = 0;
	while (n)
	{
		if (n & 1)
			count++;
		n = n >> 1;
	}
	return count;
}
int main() {
	cout << NumberOf1(-15) << endl;
	return 0;
}