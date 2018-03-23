#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

void itoa1(int i, string &number) {
	vector<char> v;
	while (i) {
		v.push_back(i%10+'0');
		i /= 10;
	}
	int j = 0;
	for (int i = v.size() - 1; i >= 0; --i)
		number = number + v[i];
}
int main() {
	string s;
	cin >> s;
	map<char,int> m;
	for (int i = 0; i < s.length(); ++i)
		m[s[i]]++;
	for (auto i = m.begin(); i != m.end(); ++i)
		cout << i->first << ":" << i->second << " ";
	cout << endl;
	bool flag = false;
	//int n = s.length();
	//string str(n, '9');
	int result=1;
	//long long max = stoi(str);
	for (int i = 1; i <= 10000; ++i) {
		string s1 = s;
		string num;
		itoa1(i, num);
		map<char,int> m1;
		for (int i = 0; i < num.length(); ++i)
			m1[num[i]]++;
		for (auto j = m1.begin(); j != m1.end(); ++j) {
			if (m1[j->first]>m[j->first])
			{
				flag = true;
				result = i;
				break;
			}
		}
		if (flag)
			break;
	}
	cout << result << endl;
	return 0;
}