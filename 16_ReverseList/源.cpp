#include <iostream>

using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :val(x), next(NULL) {
	}
};
ListNode* ReverseList(ListNode* pHead) {
	if (!pHead)
		return NULL;
	else if (!pHead->next)
		return pHead;
	else
	{
		ListNode *pAhead = NULL, *pBehind = NULL;
		ListNode *pNode = pHead;
		while (pNode)
		{
			pBehind = pNode->next; 
			pNode->next = pAhead;
			if (!pBehind)
				return pNode;
			pAhead = pNode;
			pNode = pBehind;
		}
	}
}
ListNode* ReverseList1(ListNode* pHead) {
	if (!pHead || !pHead->next)
		return pHead;
	else {
		ListNode *result = NULL;
		result = ReverseList1(pHead->next);
		pHead->next->next = pHead;
		pHead->next = NULL;
		return result;
	}
}
int main() {
	ListNode *p1 = new ListNode(1);
	ListNode *p2 = new ListNode(2);
	ListNode *p3 = new ListNode(3);
	ListNode *p4 = new ListNode(4);
	ListNode *p5 = new ListNode(5);
	p1->next = p2;
	p2->next = p3;
	p3->next = p4;
	p4->next = p5;
	ListNode* pHead = ReverseList1(p1);
	ListNode* p = pHead;
	while (p)
	{
		cout << p->val << " ";
		p = p->next;
	}
	return 0;
}