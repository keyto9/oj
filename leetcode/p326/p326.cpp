/******************************************************************************
Copyright (C), 2016, dploop
FileName: p326.cpp
Author: dploop
Date: 2016/4/22
Description: https://leetcode.com/problems/power-of-three/
******************************************************************************/
class Solution {
public:
	bool isPowerOfThree(int n) {
		return (n > 0) && (1162261467%n==0);
	}
};

