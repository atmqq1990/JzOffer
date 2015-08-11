#include<iostream>
using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :	val(x), next(NULL) {	}
};

class Solution {
public:
	ListNode* deleteDuplication(ListNode* head)
	{
		ListNode *newhead = NULL;
		ListNode *last = NULL;
		if (head == NULL || head->next == NULL)
			return head;
		ListNode *p = head->next;
		ListNode *pre = head;
		while (pre != NULL)
		{
			while (p != NULL && p->val == pre->val)
				p = p->next;
			if (p == NULL)
			{
				if (pre->next == p)
				{
					if (newhead == NULL)
					{
						newhead = pre;
						last = pre;
					}
					else
					{
						last->next = pre;
						last = last->next;
					}
				}
			}
			else
			{
				if (pre->next == p)
				{
					if (newhead == NULL)
					{
						newhead = pre;
						last = pre;
					}
					else
					{
						last->next = pre;
						last = last->next;
					}
				}
			}

			pre = p;
			if (pre != NULL)
				p = pre->next;
		}
		if (last != NULL)
			last->next = NULL;
		return newhead;
	}
};