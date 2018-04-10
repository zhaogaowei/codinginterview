#include <iostream>
#include <string>

using namespace std;

int StrToInt(string str) {
	if (str.empty()||str=="+"||str=="-")
		return 0;
	bool minus = false;
	size_t index = 0;
	if (str[0] == '-') {
		minus = true;
		index++;
	}
	else if (str[0] == '+')
		index++;
	int ans=0;
	for (size_t i = index; i < str.length(); ++i) {
		if (str[i] > '9' || str[i] < '0')
			return 0;
		else
		{
			ans = ans * 10 + str[i] - '0';
			if (ans > INT_MAX || ans < INT_MIN)
				return 0;
		}
	}
	return minus ? -1 * ans : ans;
}
int main() {
	cout << StrToInt("345234") << endl;
	return 0;
}