/******************************************************************************
Copyright (C), 2015, dploop
FileName: p137.cpp
Author: dploop
Date: 2015/11/5
Description: https://leetcode.com/problems/single-number-ii/
******************************************************************************/
const long long SHIFT = 1LL << 31;

long long mod3add(long long x, long long y) {
    int digit[21];
    for (int i = 0; i <= 20; i++) {
        digit[i] =  (x % 3 + y % 3) % 3;
        x = x / 3; y = y / 3;
    }
    long long ret = 0;
    for (int i = 20; i >= 0; i--)
        ret = ret * 3 + digit[i];
    return ret;
}

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int n = nums.size();
        vector<int> &A = nums;
        long long sum = 0LL;
        for (int i = 0; i < n; i++)
            sum = mod3add(sum, A[i] + SHIFT);
     //   if (2 == n % 3)
      //      sum = mod3add(sum, sum);
        return int(sum - SHIFT);
    }
};

