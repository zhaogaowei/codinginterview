#include <iostream>
#include <string>

using namespace std;

string add(string s1, string s2) {
	int s1_len = s1.length();
	int s2_len = s2.length();
	int n = s1_len > s2_len ? s1_len + 1 : s2_len + 1;
	string s(n, '0');
	s1 = string(n - s1_len, '0') + s1;
	s2 = string(n - s2_len, '0') + s2;
	cout << s1 << " " << s2 << endl;
	int take_over = 0;
	int nSum = 0;
	for (size_t i = n - 1; i > 0; --i) {
		nSum = s1[i] - '0' + s2[i] - '0' + take_over;
		cout << nSum << '\t';
		if (nSum >= 10) {
			s[i] = nSum - 10 + '0';
			take_over = 1;
		}
		else
		{
			s[i] = nSum + '0';
			take_over = 0;
		}
	}
	cout << s << endl;
	for (size_t i = 0; i < n; ++i) {
		if (s[i] != '0') {
			s = string(s, i, n - i);
			break;
		}
	}
	return s;
}
int main() {
	cout << add("124323423247572432464453623424", "2348929042234234373242342489239") << endl;
}