#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x):val(x),left(NULL),right(NULL){}
};

TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> in) {
	if (pre.empty() || in.empty() || pre.size()!=in.size())
		return NULL;
	TreeNode *root = new TreeNode(pre[0]);
	vector<int> pre_left, pre_right, in_left, in_right;
	int i;
	for (i = 0; i < in.size(); i++) {
		if (in[i] == pre[0])
			break;
	}
	for (int j = 0; j < i; j++) {
		pre_left.push_back(pre[j+1]);
		in_left.push_back(in[j]);
	}
	for (int j = i+1; j < pre.size(); j++) {
		pre_right.push_back(pre[j]);
		in_right.push_back(in[j]);
	}
	root->left = reConstructBinaryTree(pre_left, in_left);
	root->right = reConstructBinaryTree(pre_right, in_right);
	return root;
}
void pre_visit(TreeNode *root) {
	if (!root)
		return;
	cout << root->val << " ";
	if (root->left)
		pre_visit(root->left);
	if (root->right)
		pre_visit(root->right);
}
int main() {
	vector<int> pre = { 1,2,4,7,3,5,6,8 };
	vector<int> in = { 4,7,2,1,5,3,8,6 };
	TreeNode *root = reConstructBinaryTree(pre, in);
	pre_visit(root);
	cin.get();
	return 0;
}