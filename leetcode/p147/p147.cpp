/******************************************************************************
Copyright (C), 2015, dploop
FileName: p147.cpp
Author: dploop
Date: 2015/11/5
Description: https://leetcode.com/problems/insertion-sort-list/
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
    ListNode *insertionSortList(ListNode *head) {
        ListNode *dummy = new ListNode(0); dummy->next = head;
        ListNode *prev_j, *ptr_j, *prev_i, *ptr_i;
        prev_i = dummy; ptr_i = dummy->next;
        while (ptr_i) {
            prev_j = dummy; ptr_j = dummy->next;
            while (ptr_j->val < ptr_i->val)
                prev_j = ptr_j, ptr_j = ptr_j->next;
            if (ptr_j == ptr_i) {
                prev_i = ptr_i;
                ptr_i = ptr_i->next;
            }
            else {
                prev_i->next = ptr_i->next;
                prev_j->next = ptr_i;
                ptr_i->next = ptr_j;
                ptr_i = prev_i->next;
            }
        }
        return dummy->next;
    }
};

