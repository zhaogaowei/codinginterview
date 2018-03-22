#include <iostream>

using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};
ListNode* FindKthToTail(ListNode* pListHead, unsigned int k);

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
	ListNode *node = FindKthToTail(p1, 2);
	cout << node->val << endl;
	return 0;
}

ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
	if (!pListHead || k <= 0)
		return NULL;
	ListNode *pAhead = pListHead, *pBehind = pListHead;
	for (int i = 1; i < k; ++i) {
		if (pBehind->next)
			pBehind = pBehind->next;
		else
			return NULL;
	}
	while (pBehind->next)
	{
		pAhead = pAhead->next;
		pBehind = pBehind->next;
	}
	return pAhead;
}