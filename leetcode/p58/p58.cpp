/******************************************************************************
Copyright (C), 2016, dploop
FileName: p58.cpp
Author: dploop
Date: 2016/4/23
Description: https://leetcode.com/problems/length-of-last-word/
******************************************************************************/
class Solution {
public:
	int lengthOfLastWord(string s) {
		int slen = s.length();
		int ret = 0, i = slen - 1;
		while (i >= 0 && s[i] == ' ') --i;
		if (i < 0) return false;
		while (i >= 0 && s[i] != ' ') --i, ++ret;
		return ret;
	}
};

