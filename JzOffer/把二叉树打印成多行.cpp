#include<iostream>
#include<queue>
#include<vector>
using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {	}
};

class Solution {
public:
	vector<vector<int> > Print(TreeNode* pRoot) {
		vector<vector<int>> res;
		if (pRoot == NULL)
			return res;
		queue<TreeNode*> qu;
		TreeNode *last = pRoot;
		TreeNode *newlast = NULL;
		qu.push(pRoot);
		vector<int> temp;
	
		while (!qu.empty())
		{
			TreeNode *cur = qu.front();
			qu.pop();
			temp.push_back(cur->val);
			
			if (cur->left != NULL)
			{
				newlast = cur->left;
				qu.push(cur->left);
			}
			if (cur->right != NULL)
			{
				newlast = cur->right;
				qu.push(cur->right);
			}
			if (cur == last)
			{
				res.push_back(temp);
				temp.clear();			
				last = newlast;
			}
		}

		return res;
	}

};