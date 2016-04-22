/******************************************************************************
Copyright (C), 2016, dploop
FileName: p83.cpp
Author: dploop
Date: 2016/4/22
Description: https://leetcode.com/problems/remove-duplicates-from-sorted-list/
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
	ListNode* deleteDuplicates(ListNode* head) {
		if (!head || !head->next) return head;
		ListNode *curr=head, *next=head->next;
		for (; next; ) {
			if (curr->val == next->val) {
				curr->next = next->next;
				delete next;
				next = curr->next;
			} else {
				curr = next;
				next = next->next;
			}
		}
		return head;
	}
};

