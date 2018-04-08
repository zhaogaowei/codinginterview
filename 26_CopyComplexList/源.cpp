#include <iostream>

using namespace std;

struct RandomListNode {
	int label;
	struct RandomListNode *next, *random;
	RandomListNode(int x) :
		label(x), next(NULL), random(NULL) {
	}
};
RandomListNode* Clone(RandomListNode* pHead)
{
	if (!pHead)
		return NULL;
	RandomListNode *p = pHead;
	while (p != NULL)
	{
		RandomListNode *temp = new RandomListNode(0);
		temp->label = p->label + 1;
		temp->next = p->next;
		p->next = temp;
		p = temp->next;
	}


	p = pHead;
	while (p)
	{
		if (p->random)
			p->next->random = p->random->next;
		p = p->next->next;
	}

	RandomListNode *result = pHead->next;
	p = result;
	while (p)
	{
		p->next = p->next->next;
		p = p->next;
	}

	return result;
}
int main() {
	RandomListNode p1(1);
	RandomListNode p2(3);
	RandomListNode p3(5);
	RandomListNode p4(7);
	RandomListNode p5(9);
	p1.next = &p2;
	p2.next = &p3;
	p3.next = &p4;
	p4.next = &p3;
	p1.random = &p3;
	p2.random = &p5;
	p4.random = &p2;
	RandomListNode *copyList = Clone(&p1);
	RandomListNode *p = copyList;
	while (p)
	{
		cout << p->label << "\t";
		p = p->next;
	}
	return 0;
}