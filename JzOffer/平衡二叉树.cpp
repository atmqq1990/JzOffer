#include<iostream>
#include<algorithm>
using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {	}
};

class Solution {
public:
	bool IsBalanced_Solution(TreeNode* pRoot) {
		return balanced(pRoot);
	}

	bool balanced(TreeNode *root)
	{
		if (root == NULL)
			return true;
		bool leftbalanced = balanced(root->left);
		if (!leftbalanced)
			return false;
		bool rightbalanced = balanced(root->right);
		if (!rightbalanced)
			return false;
		int leftdep = TreeDepth(root->left);
		int rightdep = TreeDepth(root->right);
		if (leftdep - rightdep > 1 || leftdep - rightdep < -1)
			return false;
		return true;
	}

	int TreeDepth(TreeNode* pRoot)
	{
		if (pRoot == NULL)
			return 0;
		int leftdep = TreeDepth(pRoot->left);
		int rightdep = TreeDepth(pRoot->right);
		return max(leftdep, rightdep) + 1;

	}

};