#include <iostream>
#include <vector>

using namespace std;

int probability1(int n,int s) {
	if (s < n || s>6 * n)
		return 0;
	if (n == s)
		return 1;
	return probability1(n - 1, s - 1) + probability1(n - 1, s - 2) + probability1(n - 1, s - 3) +
		probability1(n - 1, s - 4) + probability1(n - 1, s - 5) + probability1(n - 1, s - 6);
}
int probability(int n, int s) {
	if (s < n || s>6 * n)
		return 0;
	if (n == s)
		return 1;
	vector<vector<int>> v(n+1,vector<int>(6*n+1,0));
	for (int i = 1; i <= n; ++i) {
		for (int j = i; j < 6 * i+1; ++j) {
			if (i==1||i == j||j==6*i)
				v[i][j] = 1;
			else
			{
				for (int k = 1; k < 7; ++k) {
					if (j - k >= i-1 && j - k <= 6 * (i-1))
						v[i][j] += v[i - 1][j - k];
				}
			}
		}
	}
	return v[n][s];
}
int main() {
	cout << probability(3, 7) << endl;
	return 0;
}