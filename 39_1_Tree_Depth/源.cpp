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
int TreeDepth(TreeNode* pRoot)
{
	if (!pRoot)
		return 0;
	int nLeft = TreeDepth(pRoot->left);
	int nright = TreeDepth(pRoot->right);
	return nLeft > nright ? nLeft + 1 : nright + 1;
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
	cout << TreeDepth(p1) << endl;
	return 0;
}