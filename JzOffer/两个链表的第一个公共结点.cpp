#include<iostream>
using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :	val(x), next(NULL) {	}
};

class Solution {
public:
	ListNode* FindFirstCommonNode(ListNode *pHead1, ListNode *pHead2) {
		if (pHead1 == NULL || pHead2 == NULL)
			return NULL;
		int len1 = length(pHead1);
		int len2 = length(pHead2);
		ListNode *p = pHead1;
		ListNode *q = pHead2;

		if (len1 > len2)
		{
			for (int i = 0; i < len1 - len2; i++)
				p = p->next;
		}
		else if (len1 < len2)
		{
			for (int i = 0; i < len2 - len1; i++)
				q = q->next;
		}
		while (p != NULL)
		{
			if (p->val == q->val)
				return p;
			p = p->next;
			q = q->next;
		}

		return NULL;
	}

	int length(ListNode *head)
	{
		int len = 0;
		while (head != NULL)
		{
			len++;
			head = head->next;
		}
		return len;
	}


};