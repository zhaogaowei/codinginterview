#include <iostream>

using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};
void Mirror(TreeNode *pRoot) {
	TreeNode *temp = new TreeNode(0);
	if (!pRoot)
		return;
	else {
		if (pRoot->left || pRoot->right) {
			temp = pRoot->left;
			pRoot->left = pRoot->right;
			pRoot->right = temp;
		}
		if (pRoot->left)
			Mirror(pRoot->left);
		if (pRoot->right)
			Mirror(pRoot->right);
	}
}
void printTree(TreeNode *root) {
	if (root)
		cout << root->val << '\t';
	if (root->left)
		printTree(root->left);
	if (root->right)
		printTree(root->right);
}
int main() {
	TreeNode *p1 = new TreeNode(1);
	TreeNode *p2 = new TreeNode(2);
	TreeNode *p3 = new TreeNode(3);
	TreeNode *p4 = new TreeNode(4);
	TreeNode *p5 = new TreeNode(5);
	TreeNode *p6 = new TreeNode(6);
	TreeNode *p7 = new TreeNode(7);
	p1->left = p2;
	p1->right = p3;
	p2->left = p4;
	p2->right = p5;
	p3->left = p6;
	p3->right = p7;
	Mirror(p1);
	printTree(p1);
	return 0;
}