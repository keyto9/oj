/******************************************************************************
Copyright (C), 2015, dploop
FileName: p136.cpp
Author: dploop
Date: 2015/10/27
Description: https://leetcode.com/problems/single-number/
******************************************************************************/
class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int ret = 0;
		for (auto x: nums) {
			ret ^= x;
		}
		return ret;
	}
};

