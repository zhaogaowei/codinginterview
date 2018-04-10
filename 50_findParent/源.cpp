#include <iostream>
#include <list>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left,*right;
	TreeNode(int x):val(x),left(NULL),right(NULL){}
};
TreeNode *getNode(list<TreeNode*> &l1, list<TreeNode*> &l2) {
	auto i1 = l1.begin(), i2 = l2.begin();
	if (*i1 != *i2)
		return NULL;
	TreeNode *result = NULL;
	while (i1 != l1.end() && i2 != l2.end()) {
		if (*i1 == *i2)
			result = *i1;
		else
			break;
		i1++;
		i2++;
	}
	return result;
}
bool getPath(TreeNode *pRoot, TreeNode *pNode, list<TreeNode *> &path) {
	if (!pRoot || !pNode)
		return false;
	if (pRoot == pNode) {
		path.push_back(pNode);
		return true;
	}
	path.push_back(pRoot);
	bool found = false;
	if (!found&&pRoot->left)
		found = getPath(pRoot->left, pNode, path);
	if (!found&&pRoot->right)
		found = getPath(pRoot->right, pNode, path);
	if (!found)
		path.pop_back();
	return found;
}
TreeNode* findParent(TreeNode *pRoot, TreeNode *p1,TreeNode* p2) {
	if (!pRoot || !p1 || !p2)
		return NULL;
	list<TreeNode*> l1, l2;
	if (!getPath(pRoot, p1, l1) || !getPath(pRoot, p2, l2))
		return NULL;
	TreeNode *result = getNode(l1, l2);
	return result;
}


int main() {
	TreeNode *p1 = new TreeNode(1);
	TreeNode *p2 = new TreeNode(2);
	TreeNode *p3 = new TreeNode(3);
	TreeNode *p4 = new TreeNode(4);
	TreeNode *p5 = new TreeNode(5);
	TreeNode *p6 = new TreeNode(6);
	TreeNode *p7 = new TreeNode(7);
	TreeNode *p8 = new TreeNode(8);
	TreeNode *p9 = new TreeNode(9);
	p1->left = p2;
	p1->right = p3;
	p2->left = p4;
	p2->right = p5;
	p4->left = p6;
	p4->right = p7;
	p5->left = p8;
	p5->right = p9;
	cout << findParent(p1, p2, p3)->val << endl;
	return 0;
}