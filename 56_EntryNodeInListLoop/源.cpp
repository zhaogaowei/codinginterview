#include <iostream>

using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};
ListNode* EntryNodeOfLoop(ListNode* pHead)
{
	if (!pHead)
		return NULL;
	ListNode *p1 = pHead, *p2 = p1->next;
	while (p1 && p2)
	{
		if (p1 != p2) {
			p1 = p1->next;
			p2 = p2->next->next;
		}
		else
			break;
	}
	if (!p1 || !p2)
		return NULL;
	int number = 1;
	p2 = p2->next;
	while (p1 != p2) {
		p2 = p2->next;
		number++;
	}
	p2 = p1 = pHead;
	for (int i = 0; i < number; ++i)
		p2 = p2->next;
	while (p1 != p2) {
		p1 = p1->next;
		p2 = p2->next;
	}
	return p1;
}
int main() {
	ListNode *p1 = new ListNode(1);
	ListNode *p2 = new ListNode(2);
	ListNode *p3 = new ListNode(3);
	ListNode *p4 = new ListNode(4);
	ListNode *p5 = new ListNode(5);
	ListNode *p6 = new ListNode(6);
	p1->next = p2;
	p2->next = p3;
	p3->next = p4;
	p4->next = p5;
	p5->next = p6;
	p6->next = p3;
	cout << EntryNodeOfLoop(p1)->val << endl;
	return 0;
}