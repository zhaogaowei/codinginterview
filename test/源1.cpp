#include<iostream>

using namespace std;

int main()
{
	int m, n;
	int b = -1;
	while (cin >> n >> m)
	{
		int sum1 = (n / (2 * m))*m*m;
		if (n % (2 * m) == 0)
		{
			cout << sum1 << endl;
			continue;
		}
		int sum2 = sum1 * 2 * m + 1;
		for (int i = sum2; i <= n; ++i) {
			int temp = i % (2 * m);			
			if (temp > 0 && temp<m+1)
				b = -1;
			else
				b = 1;
			int num = b*i;
			sum2 += num;
		}
		cout << sum1 + sum2 << endl;
	}
}