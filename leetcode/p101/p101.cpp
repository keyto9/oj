/******************************************************************************
Copyright (C), 2016, dploop
FileName: p101.cpp
Author: dploop
Date: 2016/4/23
Description: https://leetcode.com/problems/symmetric-tree/
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
	bool isSymmetric(TreeNode* root) {
		return mySymmetric(root, root);
	}
private:
	bool mySymmetric(TreeNode* fst, TreeNode* snd) {
		if (!fst && !snd) return true;
		if (fst && !snd) return false;
		if (!fst && snd) return false;
		return (fst->val==snd->val)
			&& mySymmetric(fst->left, snd->right)
			&& mySymmetric(fst->right, snd->left);
	}
};

