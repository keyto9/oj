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
    ListNode* insertionSortList(ListNode* head) {
        ListNode *ptr=head; vector<int> help;
        for (; ptr; ptr = ptr->next) {
            help.push_back(ptr->val);
        }
        sort(help.begin(), help.end());
        ptr = head; for (auto x : help) {
            ptr->val = x; ptr = ptr->next;
        }
        return head;
    }
};
