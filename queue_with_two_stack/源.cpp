#include <iostream>
#include <stack>

using namespace std;

class Solution
{
public:
	void push(int node) {
		s1.push(node);
	}

	int pop() {
		if (s2.size() <= 0) {
			while (!s1.empty())
			{
				int top = s1.top();
				s1.pop();
				s2.push(top);
			}
		}
		if (s2.empty())
			throw new exception("queue is empty!\n");
		int top = s2.top();
		s2.pop();
		return top;
	}
	bool empty() {
		return s1.empty() && s2.empty();
	}

private:
	stack<int> s1;
	stack<int> s2;
};

int main() {
	Solution s;
	for (size_t i = 0; i < 5; i++)
	{
		s.push(i);
	}
	while (!s.empty())
	{
		cout << s.pop() << endl;
	}
	cin.get();
	return 0;
}