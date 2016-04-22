/******************************************************************************
Copyright (C), 2016, dploop
FileName: p191.cpp
Author: dploop
Date: 2016/4/22
Description: https://leetcode.com/problems/number-of-1-bits/
******************************************************************************/
class Solution {
public:
	int hammingWeight(uint32_t n) {
		int ret = 0;
		for (; n; ++ret) {
			n ^= n & (-n);
		}
		return ret;
	}
};

