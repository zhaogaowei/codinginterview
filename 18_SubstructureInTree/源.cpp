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
bool DoesTree1HaveTree2(TreeNode* pRoot1, TreeNode* pRoot2) {
	if (!pRoot2)
		return true;
	if (!pRoot1)
		return false;
	if (pRoot1->val != pRoot2->val)
		return false;
	return DoesTree1HaveTree2(pRoot1->left, pRoot2->left) && DoesTree1HaveTree2(pRoot1->right, pRoot2->right);
}
bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2) {
	bool result = false;
	if (pRoot1&&pRoot2) {
		if (pRoot1->val == pRoot2->val)
			result = DoesTree1HaveTree2(pRoot1, pRoot2);
		if (!result)
			result = HasSubtree(pRoot1->left, pRoot2);
		if (!result)
			result = HasSubtree(pRoot1->right, pRoot2);
	}
	return result;
}

int main() {
	TreeNode *p1 = new TreeNode(1);
	TreeNode *p2 = new TreeNode(2);
	TreeNode *p3 = new TreeNode(3);
	TreeNode *p4 = new TreeNode(4);
	TreeNode *p5 = new TreeNode(5);
	TreeNode *p6 = new TreeNode(2);
	TreeNode *p7 = new TreeNode(4);
	TreeNode *p8 = new TreeNode(5);
	p1->left = p2;
	p1->right = p3;
	p2->left = p4;
	p2->right = p5;
	p6->left = p7;
	p7->right = p8;
	cout<<HasSubtree(p1, p6);
	return 0;
}