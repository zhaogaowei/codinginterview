#include <iostream>

using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};
ListNode* deleteDuplication(ListNode* pHead)
{
	if (!pHead)
		return NULL;
	ListNode *pre, *cur, *aft;
	pre = aft = NULL;
	cur = pHead;
	while (cur)
	{
		if (cur->next && cur->val == cur->next->val) {
			aft = cur->next;
			while (aft->next && aft->next->val == cur->val)
			{
				aft = aft->next;
			}
			if (cur == pHead)
				pHead = aft->next;
			else
				pre->next = aft->next;
			cur = aft->next;
		}
		else
		{
			pre = cur;
			cur = cur->next;
		}
	}
	return pHead;
}
int main() {
	ListNode *p1 = new ListNode(1);
	ListNode *p2 = new ListNode(1);
	ListNode *p3 = new ListNode(1);
	ListNode *p4 = new ListNode(4);
	ListNode *p5 = new ListNode(4);
	ListNode *p6 = new ListNode(4);
	ListNode *p7 = new ListNode(5);
	p1->next = p2;
	p2->next = p3;
	p3->next = p4;
	p4->next = p5;
	p5->next = p6;
	p6->next = p7;
	ListNode *p = deleteDuplication(p1);
	while (p)
	{
		cout << p->val << " ";
		p = p->next;
	}
	return 0;
}