/******************************************************************************
Copyright (C), 2016, dploop
FileName: p198.cpp
Author: dploop
Date: 2016/4/23
Description: https://leetcode.com/problems/house-robber/
******************************************************************************/
class Solution {
public:
	int rob(vector<int>& nums) {
		int dp_rob=0, dp_not=0;
		for (auto x : nums) {
			int tmp = dp_rob;
			dp_rob = dp_not + x;
			dp_not = max(dp_not, tmp);
		}
		return max(dp_rob, dp_not);
	}
};

