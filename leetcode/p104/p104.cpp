/******************************************************************************
Copyright (C), 2016, dploop
FileName: p104.cpp
Author: dploop
Date: 2016/4/21
Description: https://leetcode.com/problems/maximum-depth-of-binary-tree/
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
	int maxDepth(TreeNode* root) {
		if (!root) return 0;
		return max(maxDepth(root->left)
		  , maxDepth(root->right)) + 1;
	}
};


