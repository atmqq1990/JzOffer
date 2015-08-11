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
	TreeNode* KthNode(TreeNode* pRoot, unsigned int k)
	{
		if (k <= 0)
			return NULL;
		if (pRoot == NULL)
			return NULL;
		if (k == 1)
		{
			TreeNode *p = pRoot;
			while (p->left != NULL)
				p = p->left;
			return p;
		}
		int leftsize = nodenum(pRoot->left);
		if (leftsize < k - 1)
		{
			return KthNode(pRoot->right, k - leftsize - 1);
		}
		else if (leftsize == k - 1)
			return pRoot;
		else if (leftsize == k)
		{
			TreeNode *p = pRoot->left;
			while (p->right != NULL)
				p = p->right;
			return p;
		}
		else if (leftsize > k)
		{
			return KthNode(pRoot->left,k);
		}

	}

	int nodenum(TreeNode* root)
	{
		if (root == NULL)
			return 0;
		return nodenum(root->left) + nodenum(root->right) + 1;
	}

};