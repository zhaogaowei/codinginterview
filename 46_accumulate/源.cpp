#include <iostream>
#include <vector>

using namespace std;

int Sum_Solution(int n) {
	if (n < 0)
		return -1;
	int ans=n;
	ans && (ans += Sum_Solution(n - 1));
	return ans;
}
int sum(int n) {
	vector<vector<char>> v(n, vector<char>(n + 1));
	cout<<sizeof(v)<<endl;
	return sizeof(v) >> 1;
}
int main() {
	cout << sum(100) << endl;
	return 0;
}