#include<iostream>
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
	vector<vector<int>> res;
	vector<vector<int> > FindPath(TreeNode* root, int expectNumber) {
		if (root == NULL)
			return res;
		vector<int> pre;
		findpath(pre,root,0,expectNumber);
		return res;
	}

	void findpath(vector<int>& pre, TreeNode *cur, int presum,int expectNumber)
	{
		pre.push_back(cur->val);
		presum += cur->val;
		if (cur->left == NULL && cur->right == NULL)
		{
			if (presum == expectNumber)
			{
				res.push_back(pre);
			}
		}
		else
		{
			if(cur->left != NULL)
				findpath(pre,cur->left,presum,expectNumber);
			if(cur->right != NULL)
				findpath(pre,cur->right,presum,expectNumber);
		}
		pre.pop_back();
	}

};

/*
int main(int argc, char** args)
{
	Solution so;
	TreeNode a(10);
	TreeNode b(5);
	TreeNode c(12);
	TreeNode d(4);
	TreeNode e(7);
	a.left = &b;
	a.right = &c;
	b.left = &d;
	b.right = &e;
	vector<vector<int>> res = so.FindPath(&a,22);
	for (int i = 0; i < res.size(); i++)
	{
		for (int j = 0; j < res[i].size(); j++)
			cout << res[i][j] << " ";
		cout << endl;
	}

	system("pause");
	return 0;
}
*/