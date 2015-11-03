/******************************************************************************
Copyright (C), 2015, dploop
FileName: p26.cpp
Author: dploop
Date: 2015/11/3
Description: https://leetcode.com/problems/remove-duplicates-from-sorted-array/
******************************************************************************/
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		int ret=0, len=nums.size();
		int prev; if (len) prev=nums[0]+1;
		for (int i=0; i < len; ++i) {
			if (nums[i] != prev) {
				nums[ret++] = nums[i];
				prev = nums[i];
			}
		}
		return ret;
	}
};

