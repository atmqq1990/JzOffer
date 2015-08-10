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
	bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
	{
		if (pRoot1 != NULL && pRoot2 == NULL)
			return false;
		if (pRoot1 == NULL && pRoot2 == NULL)
			return false;
		return match(pRoot1,pRoot2);
	}


	bool match(TreeNode* pRoot1, TreeNode* pRoot2)
	{
		if (pRoot1 == NULL && pRoot2 == NULL)
			return true;
		if (pRoot1 == NULL && pRoot2 != NULL)
			return false;
		if (pRoot1 != NULL && pRoot2 == NULL)
			return true;
		if (pRoot1->val == pRoot2->val)
		{
			bool res = match(pRoot1->left, pRoot2->left);
			if (res)
				res = match(pRoot1->right, pRoot2->right);
			if (res)
				return true;
		}
		bool left = match(pRoot1->left, pRoot2);
		if (left)
			return true;
		return match(pRoot1->right, pRoot2);
	}

};

/*
int main(int argc, char** args)
{
	Solution so;
	TreeNode a(8);
	TreeNode b(8);
	TreeNode c(7);
	TreeNode d(9);
	TreeNode e(2);
	TreeNode f(4);
	TreeNode g(7);
	a.left = &b;
	a.right = &c;
	b.left = &d;
	b.right = &e;
	e.left = &f;
	e.right = &g;

	TreeNode h(8);
	TreeNode j(9);
	TreeNode k(2);
	h.left = &j;
	h.right = &k;

	bool res = so.HasSubtree(&a,&h);
	cout << res << endl;

	system("pause");
	return 0;
}
*/