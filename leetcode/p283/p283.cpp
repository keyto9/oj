/******************************************************************************
Copyright (C), 2015, dploop
FileName: p283.cpp
Author: dploop
Date: 2015/11/27
Description: https://leetcode.com/problems/move-zeroes/
******************************************************************************/
class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		int n = nums.size();
		int i = 0, j = 0;
		for (; j < n; ++j) if (nums[j]) {
			iter_swap(&nums[i], &nums[j]);
			++i;
		}
	}
};

