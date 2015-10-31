/******************************************************************************
Copyright (C), 2015, dploop
FileName: p23.cpp
Author: dploop
Date: 2015/10/31
Description: https://leetcode.com/problems/merge-k-sorted-lists/
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
	static bool cmp(const ListNode *a, const ListNode *b) {
		return a->val > b->val;
	}
	ListNode *mergeKLists(vector<ListNode *> &lists) {
		for (auto it=lists.begin(); it != lists.end(); ) {
			if (*it) ++it; else lists.erase(it);
		}
		ListNode *head = NULL, *curr = NULL;
		make_heap(lists.begin(), lists.end(), cmp);
		while (!lists.empty()) {
			if (head) curr = curr->next = lists[0];
			else head = curr = lists[0];
			pop_heap(lists.begin(), lists.end(), cmp);
			int last = lists.size() - 1;
			if (lists[last]->next) {
				lists[last] = lists[last]->next;
				push_heap(lists.begin(), lists.end(), cmp);
			}
			else {
				lists.pop_back();
			}
		}
		return head;
	}
};
