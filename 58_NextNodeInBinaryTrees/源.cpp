#include <iostream>

using namespace std;

struct TreeLinkNode {
	int val;
	struct TreeLinkNode *left;
	struct TreeLinkNode *right;
	struct TreeLinkNode *next;
	TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {

	}
};

TreeLinkNode* GetNext(TreeLinkNode* p)
{
	if (p == NULL)
		return NULL;
	if (p->right) {
		p = p->right;
		while (p->left)
			p = p->left;
		return p;
	}
	else if(p->next)
	{
		if (p->next->left == p)
			return p->next;
		else
		{
			while (p->next && p->next->right == p)
				p = p->next;
			return p->next;
		}
	}
	else
		return NULL;
}
int main() {
	TreeLinkNode *p1 = new TreeLinkNode(1);
	TreeLinkNode *p2 = new TreeLinkNode(2);
	TreeLinkNode *p3 = new TreeLinkNode(3);
	TreeLinkNode *p4 = new TreeLinkNode(4);
	TreeLinkNode *p5 = new TreeLinkNode(5);
	TreeLinkNode *p6 = new TreeLinkNode(6);
	TreeLinkNode *p7 = new TreeLinkNode(7);
	TreeLinkNode *p8 = new TreeLinkNode(8);
	TreeLinkNode *p9 = new TreeLinkNode(9);
	p1->left = p2;
	p1->right = p3;
	p2->left = p4;
	p2->right = p5;
	p2->next = p1;
	p3->left = p6;
	p3->right = p7;
	p3->next = p1;
	p4->next = p2;
	p5->left = p8;
	p5->right = p9;
	p5->next = p2;
	p6->next = p3;
	p7->next = p3;
	p8->next = p5;
	p9->next = p5;
	cout << GetNext(p7)->val << endl;
	return 0;
}