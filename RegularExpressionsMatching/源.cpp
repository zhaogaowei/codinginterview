#include <iostream>

using namespace std;

bool match(char* str, char* pattern)
{
	if (!str || !pattern)
		return false;
	if (str[0] == 0 && pattern[0] == 0)
		return true;
	if (pattern[0] != 0 && pattern[1] == '*') {
		if (match(str, pattern + 2))
			return true;
	}
	if (pattern[0] == str[0] || (pattern[0] == '.'&&str[0]!=0)) {
		if (match(str + 1, pattern + 1))
			return true;
		if (pattern[1] == '*' && match(str + 1, pattern))
			return true;
	}
	return false;
}
int main() {
	cout << match("", ".") << endl;
	return 0;
}