#include<iostream>
#include<queue>
#include<stack>
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
	vector<vector<int> > Print(TreeNode* pRoot) {
		vector<vector<int>> res;
		if (pRoot == NULL)
			return res;
		queue<TreeNode*> qu;
		TreeNode *last = pRoot;
		TreeNode *newlast = NULL;
		qu.push(pRoot);
		vector<int> temp;
		stack<int> st;
		int flag = 0;
		while (!qu.empty())
		{
			TreeNode *cur = qu.front();
			qu.pop();
			if (flag == 0)
				temp.push_back(cur->val);
			else
				st.push(cur->val);
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
				if (flag == 0)
				{
					res.push_back(temp);
					temp.clear();
				}
				else
				{
					while (!st.empty())
					{
						temp.push_back(st.top());
						st.pop();
					}
					res.push_back(temp);
					temp.clear();
				}
				last = newlast;
				flag = 1 - flag;
			}

		}

		return res;
	}

};

/*
int main(int argc, char** args)
{
	Solution so;
	TreeNode a(8);
	TreeNode b(6);
	TreeNode c(10);
	TreeNode d(5);
	TreeNode e(7);
	TreeNode f(9);
	TreeNode g(11);
	a.left = &b;
	a.right = &c;
	b.left = &d;
	b.right = &e;
	c.left = &f;
	c.right = &g;
	vector<vector<int>> res = so.Print(&a);
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