/******************************************************************************
Copyright (C), 2015, dploop
FileName: p148.cpp
Author: dploop
Date: 2015/11/5
Description: https://leetcode.com/problems/sort-list/
******************************************************************************/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 ListNode *merge(ListNode *h1, ListNode *h2) {
    ListNode *dummy = new ListNode(0); dummy->next = h1;
    ListNode *prev = dummy;
    while (h2) {
        if (!h1) {prev->next = h2; break;}
        if (h1->val <= h2->val) {
            prev = h1;
            h1 = h1->next;
            continue;
        }
        prev->next = h2;
        h2 = h2->next;
        prev = prev->next;
        prev->next = h1;
    }
    return dummy->next;
 }
 
class Solution {
public:
    ListNode *sortList(ListNode *head) {
        int num = 0;
        ListNode *ptr = head;
        while (ptr) {
            num++;
            ptr = ptr->next;
        }
        if (1 >= num) return head;
        int cnt = 0;
        ptr = head;
        while (ptr) {
            cnt++;
            if (2*cnt >= num) break;
            ptr = ptr->next;
        }
        ListNode *temp = ptr->next;
        ptr->next = NULL;
        ptr = temp;
        return merge(sortList(head), sortList(ptr));
    }
};

