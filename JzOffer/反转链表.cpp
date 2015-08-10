#include<iostream>
using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) : val(x), next(NULL) {	}
};

class Solution {
public:
	ListNode* ReverseList(ListNode* head) {
		if (head == NULL || head->next == NULL)
			return head;
		ListNode *p = head;
		ListNode *q = p->next;
		ListNode *r=NULL;
		p->next = NULL;
		while (q != NULL)
		{
			r = q->next;
			q->next = p;
			p = q;
			q = r;
		}
		return p;
	}
};