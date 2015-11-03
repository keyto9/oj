/******************************************************************************
Copyright (C), 2015, dploop
FileName: p29.cpp
Author: dploop
Date: 2015/11/3
Description: https://leetcode.com/problems/divide-two-integers/
******************************************************************************/
class Solution {
public:
	int divide(int dividend, int divisor) {
		if (dividend==INT_MIN && divisor==-1
			|| !divisor) return INT_MAX;
		return dividend / divisor;
	}
};

