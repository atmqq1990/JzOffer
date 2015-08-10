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
	void Mirror(TreeNode *pRoot) {
		if (pRoot == NULL || pRoot->left==NULL && pRoot->right==NULL)
			return;
		if (pRoot->left == NULL)
		{
			pRoot->left = pRoot->right;
			pRoot->right = NULL;
			Mirror(pRoot->left);
		}
		else if (pRoot->right == NULL)
		{
			pRoot->right = pRoot->left;
			pRoot->left = NULL;
			Mirror(pRoot->right);
		}
		else
		{
			TreeNode *temp = pRoot->left;
			pRoot->left = pRoot->right;
			pRoot->right = temp;
			Mirror(pRoot->left);
			Mirror(pRoot->right);
		}
	}
};