/******************************************************************************
Copyright (C), 2015, dploop
FileName: p35.cpp
Author: dploop
Date: 2015/11/5
Description: https://leetcode.com/problems/search-insert-position/
******************************************************************************/
class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		int len = nums.size();
		int low=0, high=len-1;
		while (low <= high) {
			int mid=(low+high)/2;
			if (nums[mid]>=target) {
				high = mid - 1;
			} else {
				low = mid + 1;
			}
		}
		return low;
	}
};

