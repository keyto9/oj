/******************************************************************************
Copyright (C), 2015, dploop
FileName: p25.cpp
Author: dploop
Date: 2015/11/3
Description: https://leetcode.com/problems/reverse-nodes-in-k-group/
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
	void reverse(ListNode *begin, ListNode *end) {
		if (!begin || begin==end) return;
		ListNode *prev = begin;
		ListNode *curr = prev->next;
		for (; curr != end; ) {
			ListNode *next = curr->next;
			curr->next = prev;
			prev = curr;
			curr = next;
		}
	}
public:
	ListNode* reverseKGroup(ListNode* head, int k) {
		ListNode foo(0); foo.next=head;
		ListNode *dmmy=&foo, *pp, *p, *q, *qq;
		dmmy->next=head; pp=dmmy; p=head;
		for (; ; ) {
			q = p;
			for (int i=1; i<k && q; ++i) {
				q = q->next;
			}
			if (!q) break;
			qq = q->next;
			reverse(p, qq);
			pp->next = q;
			p->next = qq;
			pp = p;
			p = qq;
		}
		return dmmy->next;
	}
};

