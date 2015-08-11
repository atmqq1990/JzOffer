#include<iostream>
using namespace std;

struct TreeLinkNode {
	int val;
	struct TreeLinkNode *left;
	struct TreeLinkNode *right;
	struct TreeLinkNode *next;
	TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
	TreeLinkNode* GetNext(TreeLinkNode* pNode)
	{
		if (pNode == NULL)
			return NULL;
		if (pNode->right != NULL)
		{
			pNode = pNode->right;
			while (pNode != NULL && pNode->left != NULL)
				pNode = pNode->left;
			return pNode;
		}

		TreeLinkNode* parent = pNode->next;
		while (parent != NULL && parent->left != pNode)
		{
			pNode = parent;
			parent = pNode->next;
		}

		return parent;
			
	}

};


int main(int argc, char** args)
{


}