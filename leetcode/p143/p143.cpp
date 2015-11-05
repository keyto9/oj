/******************************************************************************
Copyright (C), 2015, dploop
FileName: p143.cpp
Author: dploop
Date: 2015/11/5
Description: https://leetcode.com/problems/reorder-list/
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
    void reorderList(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        ListNode *ptr = head; int n = 0;
        while (NULL != ptr) {ptr = ptr->next; n++;}
            // count the number of nodes
            
        if (n <= 2)  return;

        ptr = head; int k = 1;
        while (2 * k < n) {ptr = ptr->next; k++;}
            // find the half positon(if n even then n/2 else (n+1)/2)
            
        ListNode *frnt = ptr->next, *temp; ptr->next = NULL;
        ptr = frnt->next; frnt->next = NULL;
            // frnt is the second list's head and now points to the half position's next
            // now ptr always points to the frnt's next node
        while (NULL != ptr) {
            // change node that ptr points to the frnt
            temp = ptr->next;
            ptr->next = frnt;
            frnt = ptr;
            ptr = temp;
        }
        ptr = head;
        while (NULL != frnt) {
            // merge the two lists
            temp = ptr->next;
            ptr->next = frnt;
            frnt = frnt->next;
            ptr->next->next = temp;
            ptr = temp;
        }
    }
};

