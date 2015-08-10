#include<iostream>
#include<queue>
#include<vector>
using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :	val(x), left(NULL), right(NULL) {	}
};

class Solution {
public:
	vector<int> PrintFromTopToBottom(TreeNode *root) {
		vector<int> res;
		if (root == NULL)
			return res;
		queue<TreeNode*> qu;
		qu.push(root);
		while (!qu.empty())
		{
			TreeNode* cur = qu.front();
			qu.pop();
			res.push_back(cur->val);
			if (cur->left != NULL)
				qu.push(cur->left);
			if (cur->right != NULL)
				qu.push(cur->right);
		}
		return res;
	}

};