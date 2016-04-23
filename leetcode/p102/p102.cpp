/******************************************************************************
Copyright (C), 2016, dploop
FileName: p102.cpp
Author: dploop
Date: 2016/4/23
Description: https://leetcode.com/problems/binary-tree-level-order-traversal/
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
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> ret;
		myDfs(root, 0, ret);
		return ret;
	}
private:
	void myDfs(TreeNode* root, int depth, vector<vector<int>>& ret) {
		if (!root) return; int ret_len = ret.size();
		if (ret_len <= depth) {
			ret.push_back(vector<int>());
		}
		ret[depth].push_back(root->val);
		myDfs(root->left, depth+1, ret);
		myDfs(root->right, depth+1, ret);
	}
};

