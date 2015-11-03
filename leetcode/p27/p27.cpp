/******************************************************************************
Copyright (C), 2015, dploop
FileName: p27.cpp
Author: dploop
Date: 2015/11/3
Description: https://leetcode.com/problems/remove-element/
******************************************************************************/
class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		int i=0, j=0, len=nums.size();
		for (; j < len; ++j) {
			if (nums[j] != val) {
				int tmp = nums[i];
				nums[i] = nums[j];
				nums[j] = tmp;
				++i;
			}
		}
		return i;
	}
};

