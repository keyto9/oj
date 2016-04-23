/******************************************************************************
Copyright (C), 2016, dploop
FileName: p189.cpp
Author: dploop
Date: 2016/4/23
Description: https://leetcode.com/problems/rotate-array/
******************************************************************************/
class Solution {
public:
	void rotate(vector<int>& nums, int k) {
		int n = nums.size();
		if (n <= 1) return; k %= n;
		reverse(&nums[0], &nums[n-k]);
		reverse(&nums[n-k], &nums[n]);
		reverse(&nums[0], &nums[n]);
	}
};

