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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *ls = NULL, *ptr = NULL, *tmp;
        for (int carry = 0; l1||l2||carry; carry /= 10) {
            if (l1) {carry += l1->val; l1 = l1->next;}
            if (l2) {carry += l2->val; l2 = l2->next;}
            tmp = new ListNode(carry % 10);
            if (!ls) {ls = ptr = tmp;}
            else {ptr = ptr->next = tmp;}
        }
        return ls;
    }
};
