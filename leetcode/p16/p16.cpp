/******************************************************************************
Copyright (C), 2015, dploop
FileName: p16.cpp
Author: dploop
Date: 2015/10/30
Description: https://leetcode.com/problems/3sum-closest/
******************************************************************************/
class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		int len=nums.size(), ret=INT_MAX/2;
		sort(nums.begin(), nums.end());
		for (int i = 0; i < len; ++i) {
			for (int j=i+1, k=len-1; j < k; ) {
				int sum=nums[i]+nums[j]+nums[k];
				int delta = sum - target;
				if (abs(ret-target) > abs(delta)) {
					ret = sum;
				}
				if (delta < 0) {
					++j; continue;
				}
				if (delta > 0) {
					--k; continue;
				}
				goto exit;
			}
		}
		exit: return ret;
	}
};
