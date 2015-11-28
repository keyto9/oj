/******************************************************************************
Copyright (C), 2015, dploop
FileName: p274.cpp
Author: dploop
Date: 2015/11/28
Description: https://leetcode.com/problems/h-index/
******************************************************************************/
class Solution {
public:
	int hIndex(vector<int>& citations) {
		int n = citations.size();
		vector<int> count(n+1, 0);
		for (int x : citations) {
			++count[min(x, n)];
		}
		int i=0, j=n; while (i<=j) {
			j -= count[i]; ++i;
		}
		return (i - 1);
	}
};

