#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};
vector<vector<int> > Print(TreeNode* pRoot) {
	vector<vector<int>> ans;
	if (!pRoot)
		return ans;
	vector<int> layer;
	int n_cur = 1;
	int n_next = 0;
	int line = 1;
	queue<TreeNode*> q;
	q.push(pRoot);
	while (!q.empty()) {
		while (n_cur--) {
			TreeNode* p = q.front();
			q.pop();
			layer.push_back(p->val);
			if (p->left) {
				n_next++;
				q.push(p->left);
			}
			if (p->right) {
				n_next++;
				q.push(p->right);
			}
		}
		if (line % 2)
			ans.push_back(layer);
		else
			ans.push_back(vector<int>(layer.rbegin(), layer.rend()));
		line++;
		layer.clear();
		n_cur = n_next;
		n_next = 0;
	}
	return ans;
}
int main() {
	TreeNode *p1 = new TreeNode(8);
	TreeNode *p2 = new TreeNode(6);
	TreeNode *p3 = new TreeNode(10);
	TreeNode *p4 = new TreeNode(5);
	TreeNode *p5 = new TreeNode(7);
	TreeNode *p6 = new TreeNode(9);
	TreeNode *p7 = new TreeNode(11);
	p1->left = p2;
	p1->right = p3;
	p2->left = p4;
	p2->right = p5;
	p3->left = p6;
	p3->right = p7;
	vector<vector<int>> v = Print(p1);
	for (auto i = 0; i < v.size(); ++i) {
		for (auto j = 0; j < v[i].size(); ++j) {
			cout << v[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}