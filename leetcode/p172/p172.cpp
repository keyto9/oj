/******************************************************************************
Copyright (C), 2016, dploop
FileName: p172.cpp
Author: dploop
Date: 2016/4/23
Description: https://leetcode.com/problems/factorial-trailing-zeroes/
******************************************************************************/
class Solution {
public:
	int trailingZeroes(int n) {
		int pow5 = 1, cnt5 = 0;
		for (; pow5 <= n/5; ) {
			pow5 = pow5 * 5;
			cnt5 += n / pow5;
		}
		return cnt5;
	}
};

