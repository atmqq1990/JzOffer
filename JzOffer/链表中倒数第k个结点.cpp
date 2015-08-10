#include<iostream>
using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* FindKthToTail(ListNode* head, unsigned int k) {
		if (head == NULL || head->next == NULL)
			return head;
		int listlen = 0;
		ListNode *p = head;
		while (p != NULL)
		{
			listlen++;
			p = p->next;
		}
		if (k > listlen)
			return NULL;
		if (k == listlen )
			return head;
		p = head;
		int size = listlen + 1 - k;
		for (int i = 1; i < size; i++)
			p = p->next;
		return p;
	}


};