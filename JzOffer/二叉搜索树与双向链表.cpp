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
	TreeNode* Convert(TreeNode* root)
	{
		if (root == NULL)
			return NULL;
		TreeNode *last = converintolist(root);
		while (last->left != NULL)
			last = last->left;
		return last;
	}

	TreeNode* converintolist(TreeNode *root)
	{
		if (root->left == NULL && root->right == NULL)
			return root;
		if (root->left != NULL)
		{
			TreeNode *leftsub = converintolist(root->left);
			root->left = leftsub;
			leftsub->right = root;
		}
		if (root->right != NULL)
		{
			TreeNode *rightsub = converintolist(root->right);
			TreeNode *temp = rightsub;
			while (temp->left != NULL)
				temp = temp->left;
			temp->left = root;
			root->right = temp;
		}

		TreeNode *p = root;
		while (p->right != NULL)
			p = p->right;
		return p;
	}

};

/*
int main(int argc, char** args)
{
	Solution so;
	TreeNode a(6);
	TreeNode b(3);
	TreeNode c(9);
	TreeNode d(1);
	TreeNode e(4);
	TreeNode f(7);
	TreeNode g(10);
	a.left = &b;
	a.right = &c;
	b.left = &d;
	b.right = &e;
	c.left = &f;
	c.right = &g;
	TreeNode *head = so.Convert(&a);
	while (head)
	{
		cout << head->val << " ";
		head = head->right;
	}
	cout << endl;

	system("pause");
	return 0;
}
*/