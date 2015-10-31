/******************************************************************************
Copyright (C), 2015, dploop
FileName: p22.cpp
Author: dploop
Date: 2015/10/31
Description: https://leetcode.com/problems/generate-parentheses/
******************************************************************************/
class Solution {
private:
	void dfs(vector<string> &ret, string tmp, int lft, int rht) {
		if (lft==0 && rht==0) {
			ret.push_back(tmp); return;
		}
		if (lft > 0) {
			dfs(ret, tmp+'(', lft-1, rht);
		}
		if (lft < rht) {
			dfs(ret, tmp+')', lft, rht-1);
		}
	}
public:
	vector<string> generateParenthesis(int n) {
		vector<string> ret;
		dfs(ret, "", n, n);
		return ret;
	}
};
