/******************************************************************************
Copyright (C), 2015, dploop
FileName: p275.cpp
Author: dploop
Date: 2015/11/28
Description: https://leetcode.com/problems/h-index-ii/
******************************************************************************/
class Solution {
public:
	int hIndex(vector<int>& citations) {
		int n = citations.size();
		int low=0, high=n-1;
		while (low <= high) {
			int mid=low+(high-low)/2;
			citations[mid]<n-mid
			? (low = mid + 1)
			: (high = mid - 1);
		}
		return (n - low);
	}
};

