/******************************************************************************
Copyright (C), 2016, dploop
FileName: p171.cpp
Author: dploop
Date: 2016/4/19
Description: https://leetcode.com/problems/excel-sheet-column-number/
******************************************************************************/
class Solution {
public:
	int titleToNumber(string s) {
		int ret = 0;
		for (auto x : s) {
			ret *= 26;
			ret += x-'A'+1;
		}
		return ret;
	}
};

