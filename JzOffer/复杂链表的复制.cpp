#include<iostream>
#include<unordered_map>
using namespace std;

struct RandomListNode {
	int label;
	struct RandomListNode *next, *random;
	RandomListNode(int x) :	label(x), next(NULL), random(NULL) {	}
};

class Solution {
public:
	RandomListNode* Clone(RandomListNode* head)
	{
		if (head == NULL)
			return NULL;
		
		unordered_map<RandomListNode*, RandomListNode*> map;
		RandomListNode *newhead = NULL;
		RandomListNode *last = NULL;
		RandomListNode *p = head;
		while (p != NULL)
		{
			if (newhead == NULL)
			{
				newhead = new RandomListNode(p->label);
				last = newhead;
				map.insert(pair<RandomListNode*,RandomListNode*>(p,newhead));
			}
			else
			{
				RandomListNode * temp = new RandomListNode(p->label);
				last->next = temp;
				last = last->next;
				map.insert(pair<RandomListNode*, RandomListNode*>(p, temp));
			}
			p = p->next;
		}
		last->next = NULL;
		p = head;
		RandomListNode *q = newhead;
		while (p != NULL)
		{
			q->random = map[p->random];
			p = p->next;
			q = q->next;
		}
		
		return newhead;
	}


};