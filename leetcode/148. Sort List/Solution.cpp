/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
ListNode *merge(ListNode *h1, ListNode *h2) {
    if (h1->val > h2->val) swap(h1, h2);
    ListNode *head = h1, *prev = h1;
    for (h1 = h1->next; h1 && h2; ) {
        if (h1->val <= h2->val) {
            prev = h1; h1 = h1->next;
        } else {
            prev = prev->next = h2;
            h2 = h2->next; prev->next = h1;
        }
    }
    if (!prev->next) prev->next = h2;
    return head;
}

class Solution {
public:
    ListNode *sortList(ListNode *head) {
        if (!head || !head->next) return head;
        ListNode *slow = head, *fast = head->next;
        do {
            fast=fast->next; if (!fast) break;
            fast=fast->next; slow=slow->next;
        } while (fast);
        fast = slow->next; slow->next = NULL;
        return merge(sortList(head), sortList(fast));
    }
};
