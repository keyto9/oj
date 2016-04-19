/******************************************************************************
Copyright (C), 2016, dploop
FileName: p338.cpp
Author: dploop
Date: 2016/4/19
Description: https://leetcode.com/problems/counting-bits/
******************************************************************************/
class Solution {
public:
    vector<int> countBits(int num) {
        ++num; assert(num >= 0);
        vector<int> ret(num, 0);
        for (int i=1; i < num; ++i) {
            ret[i] = ret[i/2] + i%2;
        }
        return ret;
    }
};

