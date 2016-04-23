/******************************************************************************
Copyright (C), 2016, dploop
FileName: p168.cpp
Author: dploop
Date: 2016/4/23
Description: https://leetcode.com/problems/excel-sheet-column-title/
******************************************************************************/
class Solution {
public:
	string convertToTitle(int n) {
		if (n <= 0) return "";
		string ret = "";
		while (1) {
			--n;
			ret = char(n%26+'A') + ret;
			n = n / 26;
			if (n <= 0) break;
		}
		return ret;
	}
};

