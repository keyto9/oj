/******************************************************************************
Copyright (C), 2015, dploop
FileName: p144.cpp
Author: dploop
Date: 2015/11/5
Description: https://leetcode.com/problems/binary-tree-preorder-traversal/
******************************************************************************/
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
struct Layer {
    TreeNode *ptr;
    bool lft, rht;
};
 
 
class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<int> ret;
        if (NULL == root) return ret;
        Layer temp; temp.ptr = root; temp.lft = temp.rht = false;
        stack<Layer> stk; stk.push(temp);
        while (!stk.empty()) {
            temp = stk.top(); stk.pop();
            if (false == temp.lft && false == temp.rht)
                ret.push_back(temp.ptr->val);
            if (false == temp.lft) {
                temp.lft = true; stk.push(temp);
                if (temp.ptr->left) {
                    temp.lft = temp.rht = false; temp.ptr = temp.ptr->left;
                    stk.push(temp);
                }
            }
            else if (false == temp.rht) {
                temp.rht = true; stk.push(temp);
                if (temp.ptr->right) {
                    temp.lft = temp.rht = false; temp.ptr = temp.ptr->right;
                    stk.push(temp);
                }
            }
            else {}
        }
        return ret;
    }
};

