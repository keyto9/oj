/******************************************************************************
Copyright (C), 2015, dploop
FileName: p6.cpp
Author: dploop
Date: 2015/10/29
Description: https://leetcode.com/problems/zigzag-conversion/
******************************************************************************/
class Solution {
public:
	string convert(string s, int nRows) {  
		if (1 == nRows) return s;
		string ret = "";
		int len = s.length(), period = 2 * (nRows - 1);
		for (int k = 0; k < nRows; k++) {
			if (0 == k || nRows - 1 == k) {
				for (int id = k; id < len; id += period) {
					ret.push_back(s[id]);
				}
			}
			else {
				int idx = k, idy = period - k;
				while (idx < len || idy < len) {
					ret.push_back(s[idx]);
					if (idy < len) ret.push_back(s[idy]);
					idx += period; idy += period;
				}
			}
		}
		return ret;
	}
};