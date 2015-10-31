/******************************************************************************
Copyright (C), 2015, dploop
FileName: p19.cpp
Author: dploop
Date: 2015/10/31
Description: https://leetcode.com/problems/remove-nth-node-from-end-of-list/
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
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		if (n<=0 || !head)  return head;
		ListNode *prev, *curr, *temp;
		for (temp=head; temp && (--n); ) {
			temp = temp->next;
		}
		if (!temp) return head;
		for (prev=curr=head; temp->next; ) {
			prev = curr;
			curr = curr->next;
			temp = temp->next;
		}
		if (prev == curr) {
			head = head->next;
		}
		else {
			prev->next = curr->next;
		}
		return head;
	}
};

