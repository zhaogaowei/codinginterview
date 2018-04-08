#include <iostream>
#include <queue>
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

vector<int> PrintFromTopToBottom(TreeNode* root) {
	vector<int> v;
	if (!root)
		return v;
	else {
		queue<TreeNode *> q;
		q.push(root);
		while (!q.empty())
		{
			TreeNode *temp = q.front();
			v.push_back(temp->val);
			if (temp->left)
				q.push(temp->left);
			if (temp->right)
				q.push(temp->right);
			q.pop();
		}
		return v;
	}
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
	vector<int> v = PrintFromTopToBottom(p1);
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << '\t';
	return 0;
}