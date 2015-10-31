/******************************************************************************
Copyright (C), 2015, dploop
FileName: p24.cpp
Author: dploop
Date: 2015/10/31
Description: https://leetcode.com/problems/swap-nodes-in-pairs/
******************************************************************************/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
	// why not?
	void swap_pair(ListNode *p, ListNode *q) {
		int tmp=p->val; p->val=q->val; q->val=tmp;
	}
public:
	ListNode* swapPairs(ListNode* head) {
		ListNode *p  = head; if (!p) return head;
		ListNode *q=p->next; if (!q) return head;
		for (; p && q; ) {
			swap_pair(p, q);
			p = q->next; if (p) q = p->next;
		}
		return head;
	}
};

