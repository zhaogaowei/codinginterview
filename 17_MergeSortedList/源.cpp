#include <iostream>

using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};

ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
{
	if (!pHead1 && !pHead2)
		return NULL;
	else if (!pHead1 && pHead2)
		return pHead2;
	else if (!pHead2 && pHead1)
		return pHead1;
	else {
		ListNode *result,*p;
		ListNode *p1 = pHead1, *p2 = pHead2;
		if (p1->val < p2->val) {
			result = p1;
			p1 = p1->next;
		}
		else {
			result = p2;
			p2 = p2->next;
		}
		p = result;
		while (p1&&p2)
		{
			if (p1->val <= p2->val) {
				ListNode *temp = new ListNode(p1->val);
				result->next = temp;
				result = temp;
				p1 = p1->next;
			}
			else {
				ListNode *temp = new ListNode(p2->val);
				result->next = temp;
				result = temp;
				p2 = p2->next;
			}
		}
		if (p1)
			result->next = p1;
		if (p2)
			result->next = p2;
		return p;
	}
}

ListNode* Merge1(ListNode* pHead1, ListNode* pHead2) {
	if (!pHead1 && !pHead2)
		return NULL;
	else if (!pHead1 && pHead2)
		return pHead2;
	else if (!pHead2 && pHead1)
		return pHead1;
	else {
		ListNode *result = NULL;
		if (pHead1->val < pHead2->val)
		{
			result = pHead1;
			result->next = Merge1(pHead1->next, pHead2);
		}
		else {
			result = pHead2;
			result->next = Merge1(pHead1, pHead2->next);
		}
		return result;
	}
}
int main() {
	ListNode *p1 = new ListNode(1);
	ListNode *p2 = new ListNode(2);
	ListNode *p3 = new ListNode(3);
	ListNode *p4 = new ListNode(4);
	ListNode *p5 = new ListNode(5);
	ListNode *p7 = new ListNode(8);
	p1->next = p3;
	p3->next = p7;
	p2->next = p4;
	p4->next = p5;
	ListNode* pHead = Merge(p1,p2);
	ListNode* p = pHead;
	while (p)
	{
		cout << p->val << " ";
		p = p->next;
	}
	return 0;
}