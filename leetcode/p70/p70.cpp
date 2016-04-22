/******************************************************************************
Copyright (C), 2016, dploop
FileName: p70.cpp
Author: dploop
Date: 2016/4/22
Description: https://leetcode.com/problems/climbing-stairs/
******************************************************************************/
class Solution {
public:
	int climbStairs(int n) {
		assert(n >= 0); int a=1, b=1;
		for (int i=0; i < n; ++i) {
			b = a + b; a = b - a;
		}
		return a;
	}
};

