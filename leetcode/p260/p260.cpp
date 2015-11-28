/******************************************************************************
Copyright (C), 2015, dploop
FileName: p260.cpp
Author: dploop
Date: 2015/11/28
Description: https://leetcode.com/problems/single-number-iii/
******************************************************************************/
class Solution {
public:
	vector<int> singleNumber(vector<int>& nums) {
		int d=0, x=0, y=0;
		for (auto e : nums) {
			d ^= e;
		}
		d = d & (-d);
		for (auto e : nums) {
			(d & e) ? (x ^= e) : (y ^= e);
		}
		vector<int> ret(2);
		ret[0] = x; ret[1] = y;
		return ret;
	}
};

