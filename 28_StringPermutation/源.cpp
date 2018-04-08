#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void subString(vector<string> &v,string str,int begin) {
	if (begin == str.size() - 1)
		v.push_back(str);
	for (int i = begin; i < str.size(); ++i) {
		if (i != begin&&str[i] == str[begin])
			continue;
		swap(str[i], str[begin]);
		subString(v, str, begin + 1);
		swap(str[i], str[begin]);
	}
}
vector<string> Permutation(string str) {
	vector<string> v;
	if (str.size() == 0)
		return v;
	subString(v, str, 0);
	sort(v.begin(), v.end());
	return v;
}
int main() {
	string s("abc");
	vector<string> v = Permutation(s);
	for (string s : v)
		cout << s << " ";
	return 0;
}