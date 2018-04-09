#include <iostream>
#include <string>

using namespace std;

string LeftRotateString(string str, int n) {
	string s1(str, 0, n);
	string s2(str, n, str.length() - n);
	string ans(s2.append(s1));
	return ans;
}
int main() {
	cout << LeftRotateString("abcdefg", 3) << endl;
	return 0;
}