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

vector<vector<int>> v;
vector<int> path;
vector<vector<int> > FindPath(TreeNode* root, int expectNumber) {
	if (!root)
		return v;
	else {
		path.push_back(root->val);
		if ((expectNumber - root->val) == 0 && root->left == NULL && root->right == NULL)
		{
			v.push_back(path);
		}
		FindPath(root->left, expectNumber - root->val);
		FindPath(root->right, expectNumber - root->val);
		if (path.size() != 0)
			path.pop_back();
		return v;
	}
}
int main() {
		TreeNode *p1 = new TreeNode(10);
		TreeNode *p2 = new TreeNode(5);
		TreeNode *p3 = new TreeNode(12);
		TreeNode *p4 = new TreeNode(4);
		TreeNode *p5 = new TreeNode(7);
		p1->left = p2;
		p1->right = p3;
		p2->left = p4;
		p2->right = p5;
		vector<vector<int>> v = FindPath(p1, 22);
		for (int i = 0; i < v.size(); ++i) {
			for (int j = 0; j < v[i].size(); ++j)
				cout << v[i][j] << '\t';
			cout << endl;
		}
		return 0;
}