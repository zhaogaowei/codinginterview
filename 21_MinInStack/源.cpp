#include <iostream>
#include <stack>

using namespace std;

class MinStack {
public:
	MinStack() {}
	void push(int value) {
		data.push(value);
		if (!minVec.size() || value < minVec.top())
			minVec.push(value);
		else
			minVec.push(minVec.top());
	}
	void pop() {
		if (!data.size() || !minVec.size())
			return;
		else {
			data.pop();
			minVec.pop();
		}
	}
	int top() {
		return data.top();
	}
	int min() {
		return minVec.top();
	}
private:
	stack<int> data;
	stack<int> minVec;
};
int main() {
	MinStack m;
	m.push(3);
	m.push(4);
	m.push(2);
	cout << m.min() << endl;
	return 0;
}