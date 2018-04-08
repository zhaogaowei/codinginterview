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
TreeNode* Convert(TreeNode* pRootOfTree)
{
	if (pRootOfTree == NULL)
		return NULL;
	TreeNode *p = NULL;
	convertNode(pRootOfTree, &p);
	return p;
}
void convertNode(TreeNode *pNode, TreeNode **p) {
	if (pNode == NULL)
		return;
	if (pNode->right != NULL)
		convertNode(pNode->right, p);
	pNode->right = *p;
	if (*p != NULL)
		(*p)->left = pNode;
	*p = pNode;
	if (pNode->left != NULL)
		convertNode(pNode->right, p);
}

int main() {

}