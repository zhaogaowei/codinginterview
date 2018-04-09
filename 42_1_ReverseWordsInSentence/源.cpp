#include <iostream>
#include <string>
#include <sstream>

using namespace std;

string reverseSentence(string &s) {
	if (s.size() <= 1)
		return s;
	string ans;
	string copy(s.rbegin(),s.rend());
	stringstream ss(copy);
	string word;
	while (ss>>word)
	{
		ans += string(word.rbegin(), word.rend()).append(" ");
	}
	ans.pop_back();
	return ans;
}
int main() {
	string s("I am a student.");
	cout << reverseSentence(s) << endl;
	return 0;
}