/******************************************************************************
Copyright (C), 2015, dploop
FileName: p142.cpp
Author: dploop
Date: 2015/11/5
Description: https://leetcode.com/problems/linked-list-cycle-ii/
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
    ListNode *detectCycle(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        ListNode *ptr = head; int flag = 0x7fffffff;
        while (NULL != ptr) {
            if (ptr->val == flag) break;
            ptr->val = flag;
            ptr = ptr->next;
        }
        return ptr;
    }
};

