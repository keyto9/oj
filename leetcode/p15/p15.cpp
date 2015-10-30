/******************************************************************************
Copyright (C), 2015, dploop
FileName: p15.cpp
Author: dploop
Date: 2015/10/30
Description: https://leetcode.com/problems/3sum/
******************************************************************************/
class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> ret;
		int len = nums.size();
		if (len <= 2) return ret;
		sort(nums.begin(), nums.end());
		int i, j, k, a, b, c;
		for (i=0; i < len; ++i) {
			if (i>0 && nums[i-1]==nums[i]) continue;
			for (j=i+1; j < len; ++j) {
				if (j>i+1 && nums[j-1]==nums[j]) continue;
				a = nums[i]; b = nums[j]; c = -a-b;
				if (binary_search(&nums[j+1], &nums[len], c)) {
					vector<int> e(3, 0);
					e[0]=a; e[1]=b; e[2]=c;
					ret.push_back(e);
				}
			}
		}
		return ret;
	}
};

