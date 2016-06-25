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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans; if (!root) return ans;
        stack<TreeNode*> stk; stk.push(root);
        TreeNode *ptr=NULL, *last=root;
        while (!stk.empty()) { ptr = stk.top();
            if ((!ptr->left && !ptr->right)
                    || ptr->right == last
                    || ptr->left  == last) {
                ans.push_back(ptr->val);
                stk.pop(); last = ptr; continue;
            }
            if (ptr->right) stk.push(ptr->right);
            if (ptr->left)  stk.push(ptr->left);
        }
        return ans;
    }
};
