#include <iostream>

using namespace std;

struct ListNode {
	int m_nValue;
	ListNode *m_pNext;
	ListNode(int i):m_nValue(i),m_pNext(NULL){}
};
void DeleteNode(ListNode **pListHead, ListNode *pToBeDeleted);
int main() {
	ListNode *p1 = new ListNode(1);
	ListNode *p2 = new ListNode(2);
	ListNode *p3 = new ListNode(3);
	ListNode *p4 = new ListNode(4);
	ListNode *p5 = new ListNode(5);
	p1->m_pNext = p2;
	p2->m_pNext = p3;
	p3->m_pNext = p4;
	p4->m_pNext = p5;
	ListNode *pnext = p1;
	DeleteNode(&p1,p5);
	while (pnext)
	{
		cout << pnext->m_nValue << endl;
		pnext = pnext->m_pNext;
	}
	return 0;
}
void DeleteNode(ListNode **pListHead, ListNode *pToBeDeleted) {
	if (!pListHead || !pToBeDeleted)
		return;
	if (pToBeDeleted->m_pNext) {
		ListNode *pNext = pToBeDeleted->m_pNext;
		pToBeDeleted->m_nValue = pNext->m_nValue;
		pToBeDeleted->m_pNext = pNext->m_pNext;
		delete pNext;
		pNext = NULL;
	}
	else if (*pListHead == pToBeDeleted) {
		delete pToBeDeleted;
		pToBeDeleted = NULL;
		*pListHead = NULL;
	}
	else
	{
		ListNode *pNode = *pListHead;
		while (pNode->m_pNext!=pToBeDeleted)
			pNode = pNode->m_pNext;
		pNode->m_pNext = NULL;
		delete pToBeDeleted;
		pToBeDeleted = NULL;
	}
}