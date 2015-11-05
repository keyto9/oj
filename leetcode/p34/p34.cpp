/******************************************************************************
Copyright (C), 2015, dploop
FileName: p34.cpp
Author: dploop
Date: 2015/11/5
Description: https://leetcode.com/problems/search-for-a-range/
******************************************************************************/
class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		vector<int> ret;
		ret.push_back(search_great_equal(nums, target));
		ret.push_back(search_less_equal(nums, target));
		return ret;
	}
	int search_great_equal(vector<int> &nums, int target) {
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
		int ret = -1;
		if (low<len && nums[low]==target) {
			ret = low;
		}
		return ret;
	}
	int search_less_equal(vector<int> &nums, int target) {
		int len = nums.size();
		int low=0, high=len-1;
		while (low <= high) {
			int mid=(low+high)/2;
			if (nums[mid]<=target) {
				low = mid + 1;
			} else {
				high = mid - 1;
			}
		}
		int ret = -1;
		if (high>=0 && nums[high]==target) {
			ret = high;
		}
		return ret;
	}
};
