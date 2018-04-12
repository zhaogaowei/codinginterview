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
bool isSymmetricalCore(TreeNode *pl, TreeNode *pr) {
	if (pl == NULL && pr == NULL)
		return true;
	if (pl == NULL || pr == NULL)
		return false;
	if (pl->val != pr->val)
		return false;
	return (isSymmetricalCore(pl->left, pr->right) && isSymmetricalCore(pl->right, pr->left));
}
bool isSymmetrical(TreeNode* pRoot)
{
	return isSymmetricalCore(pRoot, pRoot);
}
int main() {

}