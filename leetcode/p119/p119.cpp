/******************************************************************************
Copyright (C), 2016, dploop
FileName: p119.cpp
Author: dploop
Date: 2016/4/23
Description: https://leetcode.com/problems/pascals-triangle-ii/
******************************************************************************/
class Solution {
public:
	vector<int> getRow(int rowIndex) {
		vector<int> ret(rowIndex+1, 1);
		for (int i=2; i <= rowIndex; ++i) {
			for (int j=i-1; j > 0; --j) {
				ret[j] = ret[j-1] + ret[j];
			}
		}
		return ret;
	}
};

