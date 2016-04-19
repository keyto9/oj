/******************************************************************************
Copyright (C), 2016, dploop
FileName: p342.cpp
Author: dploop
Date: 2016/4/19
Description: https://leetcode.com/problems/power-of-four/
******************************************************************************/
class Solution {
public:
	bool isPowerOfFour(int num) {
		bool isPowerOfTwo = (num > 0)
			&& (num == (num&(-num)));
		return isPowerOfTwo
				&& (num & 0x55555555);
	}
};

