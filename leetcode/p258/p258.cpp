/******************************************************************************
Copyright (C), 2015, dploop
FileName: p258.cpp
Author: dploop
Date: 2015/11/28
Description: https://leetcode.com/problems/add-digits/
******************************************************************************/
class Solution {
public:
	int addDigits(int num) {
		if (num <= 0) {
			return 0;
		} else {
			num %= 9;
			return (num ? num : 9);
		}
	}
};

