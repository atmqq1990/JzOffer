#include<iostream>
using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :	val(x), next(NULL) { }
};

class Solution {
public:
	ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
	{
		if (pHead1 == NULL)
			return pHead2;
		if (pHead2 == NULL)
			return pHead1;
		ListNode *newhead = NULL;
		ListNode *last = NULL;
		if (pHead1->val <= pHead2->val)
		{
			newhead = pHead1;
			last = pHead1;
			pHead1 = pHead1->next;
			last->next = NULL;
		}
		else
		{
			newhead = pHead2;
			last = pHead2;
			pHead2 = pHead2->next;
			last->next = NULL;
		}

		while (pHead1 != NULL && pHead2 != NULL)
		{
			if (pHead1->val <= pHead2->val)
			{
				last->next = pHead1;
				pHead1 = pHead1->next;
			}
			else
			{
				last->next = pHead2;
				pHead2 = pHead2->next;			
			}
			last = last->next;
			last->next = NULL;
		}

		if (pHead1 != NULL)
			last->next = pHead1;
		if (pHead2 != NULL)
			last->next = pHead2;
		
		return newhead;
	}

};