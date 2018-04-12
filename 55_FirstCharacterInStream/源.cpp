#include <iostream>
#include <deque>
using namespace std;

class Solution
{
public:
	//Insert one char from stringstream
	void Insert(char ch)
	{
		++hashArray[ch - '\0'];
		if (hashArray[ch - '\0'] == 1) {
			data.push_back(ch);
		}
	}
	//return the first appearence once char in current stringstream
	char FirstAppearingOnce()
	{
		while (!data.empty() && hashArray[data.front()] >= 2) {
			data.pop_front();
		}
		if (data.empty())
			return '#';
		return data.front();
	}

private:
	unsigned char hashArray[128];
	deque<char> data;
};
int main() {

}