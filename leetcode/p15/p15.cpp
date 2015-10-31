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
		sort(nums.begin(), nums.end());
		for (int i=0; i < len; ++i) {
			if (i>0 && nums[i-1]==nums[i]) {
				continue;
			}
			for (int j=i+1, k=len-1; j < k; ) {
				if (j>i+1 && nums[j-1]==nums[j]) {
					++j; continue;
				}
				if (k<len-1 && nums[k+1]==nums[k]) {
					--k; continue;
				}
				int a=nums[i], b=nums[j], c=nums[k];
				int sum = a + b + c;
				if (sum > 0) {
					--k; continue;
				}
				if (sum < 0) {
					++j; continue;
				}
				vector<int> e(3, 0);
				e[0]=a; e[1]=b; e[2]=c;
				ret.push_back(e);
				++j; --k;
			}
		}
		return ret;
	}
};

