/******************************************************************************
Copyright (C), 2016, dploop
FileName: p206.cpp
Author: dploop
Date: 2016/4/22
Description: https://leetcode.com/problems/reverse-linked-list/
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
	ListNode* reverseList(ListNode* head) {
		if (!head || !head->next) return head;
		ListNode *prev=NULL, *curr=head;
		for (ListNode *next; curr; ) {
			next = curr->next;
			curr->next = prev;
			prev = curr; curr = next;
		}
		return prev;
	}
};

