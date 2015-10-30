/******************************************************************************
Copyright (C), 2015, dploop
FileName: p14.cpp
Author: dploop
Date: 2015/10/30
Description: https://leetcode.com/problems/longest-common-prefix/
******************************************************************************/
class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		string ret; int n=strs.size();
		if (n <= 0) return ret;
		int l=INT_MAX; for (auto s : strs) {
			int t=s.length();
			l = min(l, t);
		}
		for (int i=0; i < l; ++i) {
			for (int j=1; j < n; ++j) {
				if (strs[j][i] != strs[0][i]) {
					return ret;
				}
			}
			ret.push_back(strs[0][i]);
		}
		return ret;
	}
};

