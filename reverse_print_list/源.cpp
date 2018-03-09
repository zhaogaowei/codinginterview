#include <iostream>
#include <stack>
#include <vector>

using namespace std;

struct ListNode
{
	int value;
	struct ListNode *pNext;
	ListNode(int x) :value(x), pNext(NULL) {}
};
vector<int> printListFromTailToHead(ListNode* head) {
	vector<int> v1;
	if (head == NULL)
		return v1;
	stack<ListNode> s;
	ListNode *pNode = head;
	while (pNode != NULL) {
		s.push(*pNode);
		pNode = pNode->pNext;
	}
	while (!s.empty())
	{
		v1.push_back(s.top().value);
		s.pop();
	}
	return v1;
}
int main() {
	ListNode n1(1);
	ListNode n2(2);
	ListNode n3(3);
	ListNode n4(4);
	ListNode n5(5);
	n1.pNext = &n2;
	n2.pNext = &n3;
	n3.pNext = &n4;
	n4.pNext = &n5;
	vector<int> v = printListFromTailToHead(&n1);
	for (auto num : v)
		cout << num << " ";
	cout << endl;
	cin.get();
	return 0;
}