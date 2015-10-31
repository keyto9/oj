/******************************************************************************
Copyright (C), 2015, dploop
FileName: p18.cpp
Author: dploop
Date: 2015/10/31
Description: https://leetcode.com/problems/4sum/
******************************************************************************/
class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		vector<vector<int>> ret; int len=nums.size();
		sort(nums.begin(), nums.end());
		for (int i = 0; i < len; ++i) {
			if (i > 0 && nums[i-1]==nums[i]) continue;
			for (int j=i+1; j < len; ++j) {
				if (j>i+1 && nums[j-1]==nums[j]) continue;
				for (int p=j+1, q=len-1; p < q; ) {
					if (p > j+1 && nums[p-1]==nums[p]) {
						++p; continue;
					}
					if (q<len-1 && nums[q+1]==nums[q]) {
						--q; continue;
					}
					int a=nums[i], b=nums[j], c=nums[p], d=nums[q];
					int sum = a + b + c + d;
					if (sum < target) {
						++p; continue;
					}
					if (sum > target) {
						--q; continue;
					}
					vector<int> e(4, 0);
					e[0]=a; e[1]=b; e[2]=c; e[3]=d;
					ret.push_back(e);
					++p; --q;
				}
			}
		}
		return ret;
	}
};

