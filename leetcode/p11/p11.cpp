/******************************************************************************
Copyright (C), 2015, dploop
FileName: p11.cpp
Author: dploop
Date: 2015/10/29
Description: https://leetcode.com/problems/container-with-most-water/
******************************************************************************/
class Solution {
public:
	int maxArea(vector<int> &h) {
		int ret=0, low=0, high=h.size()-1;
		for (; low < high; ) {
			if (h[low] < h[high]) {
				ret = max(ret, (high-low)*h[low]);
				++low;
			}
			else {
				ret = max(ret, (high-low)*h[high]);
				--high;
			}
		}
		return ret;
	}
};

