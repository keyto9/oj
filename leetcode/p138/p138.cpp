/******************************************************************************
Copyright (C), 2015, dploop
FileName: p138.cpp
Author: dploop
Date: 2015/11/5
Description: https://leetcode.com/problems/copy-list-with-random-pointer/
******************************************************************************/
/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        RandomListNode *dummy1 = new RandomListNode(0);
        RandomListNode *dummy2 = new RandomListNode(0);
        
        dummy1->next = head;
        
        unordered_map<RandomListNode*, RandomListNode*> mp;
        mp[NULL] = NULL;
        
        RandomListNode *ptr1 = dummy1, *ptr2 = dummy2;
        while (NULL != ptr1->next) {
            ptr2->next = new RandomListNode(ptr1->next->label);
            mp[ptr1->next] = ptr2->next;
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        
        ptr1 = dummy1; ptr2 = dummy2;
        while (NULL != ptr1->next) {
            ptr2->next->random = mp[ptr1->next->random];
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        
        return dummy2->next;
    }
};

