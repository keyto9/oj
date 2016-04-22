/******************************************************************************
Copyright (C), 2016, dploop
FileName: p169.cpp
Author: dploop
Date: 2016/4/22
Description: https://leetcode.com/problems/majority-element/
******************************************************************************/
class Solution {
public:
	int majorityElement(vector<int>& nums) {
		int len = nums.size(); assert(len > 0);
		int acc = nums[0], acc_cnt = 1;
		for (int i=1; i < len; ++i) {
			if (acc_cnt > 0) {
				acc_cnt += (acc == nums[i])
								? 1 : -1;
			} else {
				acc = nums[i];
				acc_cnt = 1;
			}
		}
		return acc;
	}
};

