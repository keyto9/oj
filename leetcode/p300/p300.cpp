/******************************************************************************
Copyright (C), 2015, dploop
FileName: p300.cpp
Author: dploop
Date: 2015/11/5
Description: https://leetcode.com/problems/longest-increasing-subsequence/
******************************************************************************/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len=nums.size(), ret=0;
        vector<int> stk(len+1, 0);
        for (auto x : nums) {
            int low=1, high=ret;
            while (low <= high) {
                int mid=(low+high)/2;
                if (stk[mid] >= x) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            stk[low] = x;
            if (ret < low) {
                ret = low;
            }
        }
        return ret;
    }
};

