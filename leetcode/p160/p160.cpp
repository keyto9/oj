/******************************************************************************
Copyright (C), 2016, dploop
FileName: p160.cpp
Author: dploop
Date: 2016/4/23
Description: https://leetcode.com/problems/intersection-of-two-linked-lists/
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
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		ListNode *ptrA = headA, *ptrB = headB;
		while (ptrA != ptrB) { 
			ptrA = ptrA ? ptrA->next : headB;
			ptrB = ptrB ? ptrB->next : headA;
		}
		return ptrA;
	}
};

