/******************************************************************************
Copyright (C), 2015, dploop
FileName: p226.cpp
Author: dploop
Date: 2015/11/5
Description: https://leetcode.com/problems/invert-binary-tree/
******************************************************************************/
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
    TreeNode* invertTree(TreeNode* root) {
    	if (!root) return root;
    	TreeNode *left = root->left;
    	TreeNode *right = root->right;
    	root->left = invertTree(right);
    	root->right = invertTree(left);
        return root;
    }
};
