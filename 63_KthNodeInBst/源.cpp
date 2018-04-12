#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};
void KthNode(TreeNode* pRoot,vector<TreeNode*> &arr) {
	if (pRoot == nullptr)
		return;
	if (pRoot->left)
		KthNode(pRoot->left,arr);
	arr.push_back(pRoot);
	if (pRoot->right)
		KthNode(pRoot->right,arr);
}
TreeNode* KthNode(TreeNode* pRoot, int k)
{
	if (pRoot == nullptr || k <= 0)
		return NULL;
	vector<TreeNode*> v;
	KthNode(pRoot, v);
	if (k > v.size())
		return NULL;
	else
		return v[k - 1];
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
	cout << KthNode(p1, 4)->val << endl;
	return 0;
}