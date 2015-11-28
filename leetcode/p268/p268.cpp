/******************************************************************************
Copyright (C), 2015, dploop
FileName: p268.cpp
Author: dploop
Date: 2015/11/28
Description: https://leetcode.com/problems/missing-number/
******************************************************************************/
class Solution {
public:
	int missingNumber(vector<int>& nums) {
		int n = nums.size(), r = 0;
		for (int i=0; i < n; ++i) {
			r ^= (i+1) ^ nums[i];
		}
		return r;
	}
};

