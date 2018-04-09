#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

int FirstNotRepeatingChar(string str) {
	map<char, int> m;
	int ans = 0;
	int index = str.length()-1;
	for (int i = 0; i < str.length(); ++i)
		m[str[i]]++;
	for (auto i = m.begin(); i != m.end(); ++i) {
		if (i->second == 1) {
			index = min(index, (int)str.find_first_of(i->first));
		}
	}
	return index;
}
int main() {
	cout << FirstNotRepeatingChar("abacdeff") << endl;
	return 0;
}