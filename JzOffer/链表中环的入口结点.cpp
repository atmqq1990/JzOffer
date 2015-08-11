#include<iostream>
using namespace std;


struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :	val(x), next(NULL) {	}
};

class Solution {
public:
	ListNode* EntryNodeOfLoop(ListNode* head)
	{
		if (head == NULL || head->next == head)
			return head;

		ListNode *p = head;
		ListNode *q = head;

		while (q != NULL && q->next != NULL)
		{
			q = q->next->next;
			p = p->next;
			if (p == q)
				break;
		}

		if (q == NULL || q->next == NULL)
			return NULL;

		ListNode *r = p;
		ListNode *temp = head;
		while (r != temp)
		{
			r = r->next;
			temp = temp->next;
		}
		return r;
	}
};