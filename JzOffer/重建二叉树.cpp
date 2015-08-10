#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	struct TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> in) {
		return recover(pre, 0, pre.size() - 1, in, 0, in.size() - 1);
	}

	TreeNode *recover(vector<int>& pre, int pleft, int pright, vector<int>& in, int inleft, int inright)
	{
		if (pright < pleft)
			return NULL;
		TreeNode *root = new TreeNode(pre[pleft]);
		if (pright - pleft == 0)
			return root;
		int leftsize = 0;
		while (in[inleft + leftsize] != pre[pleft])
			leftsize++;
		TreeNode *leftroot = recover(pre, pleft + 1, pleft + leftsize, in, inleft, inleft + leftsize - 1);
		TreeNode *rightroot = recover(pre, pleft + leftsize + 1, pright, in, inleft + leftsize + 1, inright);
		root->left = leftroot;
		root->right = rightroot;
		return root;
	}
};