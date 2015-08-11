#include<iostream>
using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :	val(x), left(NULL), right(NULL) {	}
};

class Solution {
public:
	bool isSymmetrical(TreeNode* pRoot)
	{
		if (pRoot == NULL)
			return true;
		return isSys(pRoot->left, pRoot->right);
	}


	bool isSys(TreeNode *root1, TreeNode *root2)
	{
		if (root1 == NULL && root2 != NULL || root1 != NULL && root2 == NULL)
			return false;
		if (root1 == NULL && root2 == NULL)
			return true;
		if (root1->val != root2->val)
			return false;
		return isSys(root1->left, root2->right) && isSys(root1->right, root2->left);

	}

};