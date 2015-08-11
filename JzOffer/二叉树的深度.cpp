#include<iostream>
#include<algorithm>
using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :	val(x), left(NULL), right(NULL) {	}
};

class Solution {
public:
	int TreeDepth(TreeNode* pRoot)
	{
		if (pRoot == NULL)
			return 0;
		int leftdep = TreeDepth(pRoot->left);
		int rightdep = TreeDepth(pRoot->right);
		return max(leftdep,rightdep) + 1;

	}
};