#include <iostream>

using namespace std;

int NumberOf1Between1AndN_Solution(int n)
{
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		int number = 0;
		int m = i;
		while (m)
		{
			if (m % 10 == 1)
				number++;
			m /= 10;
		}
		ans += number;
	}
	return ans;
}
int main() {
	cout << NumberOf1Between1AndN_Solution(21435);
	return 0;
}