#include <iostream>
#include <string>

using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};
void Serialize(TreeNode *root, string &s) {
	if (root == nullptr)
	{
		s.append("#,");
	}
	else {
		s.append(to_string(root->val) + ",");
		Serialize(root->left, s);
		Serialize(root->right, s);
	}
}
char* Serialize(TreeNode *root) {
	if (root == nullptr)
		return NULL;
	string s;
	Serialize(root, s);
	char *ans = new char[s.length()];
	for (int i = 0; i < s.length()-1; ++i)
		ans[i] = s[i];
	ans[s.length()] = '\0';
	return ans;
}
TreeNode* Deserialize(char **str) {
	if (**str == '#') {
		(*str)++;
		return NULL;
	}
	int num = 0;
	while (**str!=',' && **str != '#')
	{
		num = num * 10 + **str - '0';
		(*str)++;
	}
	TreeNode *root = new TreeNode(num);
	if (**str == '\0')
		return root;
	else
		(*str)++;
	root->left = Deserialize(str);
	root->left = Deserialize(str);
	return root;
}
TreeNode* Deserialize(char *str) {
	if(str==nullptr)
		return NULL;
	return Deserialize(&str);
}
int main() {
	TreeNode *p1 = new TreeNode(1);
	TreeNode *p2 = new TreeNode(2);
	TreeNode *p3 = new TreeNode(3);
	TreeNode *p4 = new TreeNode(4);
	TreeNode *p5 = new TreeNode(5);
	TreeNode *p6 = new TreeNode(6);
	p1->left = p2;
	p1->right = p3;
	p2->left = p4;
	p3->left = p5;
	p3->right = p6;
	string s = Serialize(p1);
	cout << s << endl;

	return 0;
}