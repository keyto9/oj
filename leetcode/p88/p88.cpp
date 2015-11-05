/******************************************************************************
Copyright (C), 2015, dploop
FileName: p88.cpp
Author: dploop
Date: 2015/11/5
Description: https://leetcode.com/problems/merge-sorted-array/
******************************************************************************/
class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		int i=m-1, j=n-1, k=m+n-1;
		while (i>=0 && j>=0) {
			int x=nums1[i], y=nums2[j];
			if (x >= y) {
				nums1[k] = x;
				--i; --k;
			} else {
				nums1[k] = y;
				--j; --k;
			}
		}
		while (j >= 0) {
			nums1[k] = nums2[j];
			--j; --k;
		}
	}
};

