/******************************************************************************
Copyright (C), 2015, dploop
FileName: p231.cpp
Author: dploop
Date: 2015/11/5
Description: https://leetcode.com/problems/power-of-two/
******************************************************************************/
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return (n <= 0) ? false
                : (n == n&(-n));
    }
};


