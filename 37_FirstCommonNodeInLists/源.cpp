#include <iostream>

using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};
ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {
	if (!pHead1 || !pHead2)
		return NULL;
	int l1 = 0, l2 = 0;
	ListNode *p = pHead1;
	while (p) {
		l1++;
		p = p->next;
	}
	p = pHead2;
	while (p) {
		l2++;
		p = p->next;
	}
	ListNode *p1 = pHead1, *p2 = pHead2;
	if (l1 > l2) {
		for (int i = 0; i < l1 - l2; ++i)
			p1 = p1->next;
	}
	else
	{
		for (int i = 0; i < l2 - l1; ++i)
			p2 = p2->next;
	}
	
	while (p1&&p2)
	{
		if (p1->val == p2->val) {
			p = p1;
			break;
		}
		p1 = p1->next;
		p2 = p2->next;
	}
	return p;
}
int main() {
	ListNode *p1 = new ListNode(1);
	ListNode *p2 = new ListNode(2);
	ListNode *p3 = new ListNode(3);
	ListNode *p4 = new ListNode(4);
	ListNode *p5 = new ListNode(5);
	ListNode *p6 = new ListNode(6);
	ListNode *p7 = new ListNode(7);
	p1->next = p2;
	p2->next = p3;
	p3->next = p6;
	p6->next = p7;
	p4->next = p5;
	p5->next = p6;
	cout << FindFirstCommonNode(p1, p4)->val << endl;
	return 0;
}