#include <iostream>
#include <list>

using namespace std;

int LastRemaining_Solution(int n, int m)
{
	list<int> l;
	for (int i = 0; i < n; i++) {
		l.push_back(i);
	}
	auto i = l.begin();
	int ans;
	while (l.size())
	{
		for (int j = 1; j < m; j++) {
			i++;
			if (i == l.end())
				i = l.begin();
		}
		ans = *i;
		auto next = ++i;
		if (next == l.end())
			next = l.begin();
		--i;
		l.erase(i);
		i = next;
	}
	return ans;
}
int last(int n, int m) {
	if (n < 1 || m < 1)
		return -1;
	int last = 0;
	for (int i = 2; i <= n; i++)
		last = (last + m) % i;
	return last;
}
int main() {
	cout << last(5, 1) << endl;
	return 0;
}