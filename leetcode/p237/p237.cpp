/******************************************************************************
Copyright (C), 2016, dploop
FileName: p237.cpp
Author: dploop
Date: 2016/4/21
Description: https://leetcode.com/problems/delete-node-in-a-linked-list/
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
	void deleteNode(ListNode* node) {
		ListNode *tmp = node->next;
		node->next = tmp->next;
		node->val = tmp->val;
		// free tmp
	}
};

