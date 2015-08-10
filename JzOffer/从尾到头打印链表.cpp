#include<iostream>
#include<vector>
#include<stack>
using namespace std;

struct ListNode {
        int val;
        struct ListNode *next;
        ListNode(int x) :
              val(x), next(NULL) {
        }
};

class Solution {
public:
	vector<int> printListFromTailToHead(struct ListNode* head) {
		vector<int> res;
		if (head == NULL)
			return res;
		stack<int> st;
		ListNode *p = head;
		while (p != NULL)
		{
			st.push(p->val);
			p = p->next;
		}
		while (!st.empty())
		{
			res.push_back(st.top());
			st.pop();
		}
		return res;
	}
};