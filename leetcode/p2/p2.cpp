/******************************************************************************
Copyright (C), 2015, dploop
FileName: p2.cpp
Author: dploop
Date: 2015/10/28
Description: https://leetcode.com/problems/add-two-numbers/
******************************************************************************/
class Solution {
public:
	ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
		ListNode *ls=NULL, *p=NULL; int carry = 0;
		for (; l1 || l2 || carry; ) {
			if (l1) {
				carry += l1->val;
				l1 = l1->next;
			}
			if (l2) {
				carry += l2->val;
				l2 = l2->next;
			}
			ListNode *t = new ListNode(carry % 10);
			if (!ls) {
				ls = p = t;
			}
			else {
				p->next = t;
				p = t;
			}
			carry = carry / 10;
		}
		return ls;
	}
};
