/******************************************************************************
Copyright (C), 2016, dploop
FileName: p343.cpp
Author: dploop
Date: 2016/4/19
Description: https://leetcode.com/problems/reverse-string/
******************************************************************************/
class Solution {
public:
	string reverseString(string s) {
		reverse(s.begin(), s.end());
		return s;
	}
};

