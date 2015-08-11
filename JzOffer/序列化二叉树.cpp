#include<iostream>
#include<stack>
#include<string>
using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :	val(x), left(NULL), right(NULL) {	}
};

class Solution {
public:
	string str;
	int index = 0;

	char* Serialize(TreeNode *root) {
		if(str.size() > 0)
			str.clear();
		ser(root);
		return (char*)str.c_str();
	}

	void ser(TreeNode *root)
	{
		if (root == NULL)
		{
			str.push_back('#');
			str.push_back(' ');
			return;
		}
		str.append(to_string(root->val));
		str.push_back(' ');
		ser(root->left);
		ser(root->right);
	}


	TreeNode* Deserialize(char *str) {
		if (str[index] == ' ')
			index++;
		if (str[index] == '#' || str[index]=='\0')
		{
			index++;
			return NULL;
		}
		string value;
		while (str[index] != ' ')
		{
			value.push_back(str[index]);
			index++;
		}
		TreeNode *root = new TreeNode(atoi(value.c_str()));
		root->left = Deserialize(str);
		root->right = Deserialize(str);
		return root;
	}

};