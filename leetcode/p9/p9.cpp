/******************************************************************************
Copyright (C), 2015, dploop
FileName: p9.cpp
Author: dploop
Date: 2015/10/29
Description: https://leetcode.com/problems/palindrome-number/
******************************************************************************/
class Solution {
public:
	bool isPalindrome(int x) {
		if (x < 0) return false;
		int hg = 1; while (x/hg >= 10) hg *= 10;
		while (x) {
			if (x / hg != x % 10) return false;
			x %= hg; x /= 10; hg /= 100;
		}
		return true;
	}
};

