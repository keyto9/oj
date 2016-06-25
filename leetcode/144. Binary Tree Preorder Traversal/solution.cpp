/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans; if (!root) return ans;
        stack<TreeNode*> stk; TreeNode *ptr=root;
        while (!stk.empty() || ptr) {
            if (ptr) {
                ans.push_back(ptr->val);
                stk.push(ptr); ptr = ptr->left;
            } else {
                ptr = stk.top(); stk.pop();
                ptr = ptr->right;
            }
        }
        return ans;
    }
};
