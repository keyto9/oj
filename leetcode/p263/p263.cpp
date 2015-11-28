/******************************************************************************
Copyright (C), 2015, dploop
FileName: p263.cpp
Author: dploop
Date: 2015/11/28
Description: https://leetcode.com/problems/ugly-number/
******************************************************************************/
class Solution {
public:
	bool isUgly(int num) {
		if (num <= 0) return false;
		int n = num, d = 2;
		for (; d <= 5; ++d) {
			for (; 0==n%d; n/=d);
		}
		return n == 1;
	}
};

