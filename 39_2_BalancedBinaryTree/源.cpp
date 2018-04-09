#include <iostream>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) :val(x),left(NULL),right(NULL){}
};
int TreeDepth(TreeNode* pRoot)
{
	if (!pRoot)
		return 0;
	int nLeft = TreeDepth(pRoot->left);
	int nright = TreeDepth(pRoot->right);
	return nLeft > nright ? nLeft + 1 : nright + 1;
}
bool IsBalanced_Solution(TreeNode* pRoot) {
	if (!pRoot)
		return true;
	int h_left = TreeDepth(pRoot->left);
	int h_right= TreeDepth(pRoot->right);
	int diff = h_left - h_right;
	if (diff < -1 || diff >1)
		return false;
	bool b_left = IsBalanced_Solution(pRoot->left);
	bool b_right = IsBalanced_Solution(pRoot->right);
	return b_left&&b_right;
}
bool isBalanceCore(TreeNode* pRoot, int *depth) {
	if (pRoot == NULL)
		return true;
	int left = 0, right = 0;
	if (isBalanceCore(pRoot->left, &left) && isBalanceCore(pRoot->right, &right)) {
		int diff = left - right;
		if (diff <= 1 && diff >= -1) {
			*depth = 1 + (left > right ? right : left);
			return true;
		}
	}
	return false;
}
bool isBalanced(TreeNode* pRoot) {
	int depth = 0;
	return isBalanceCore(pRoot, &depth);
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
	p5->left = p7;
	p3->right = p6;
	cout << isBalanced(p1) << endl;
	return 0;
}