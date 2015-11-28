/******************************************************************************
Copyright (C), 2015, dploop
FileName: p278.cpp
Author: dploop
Date: 2015/11/28
Description: https://leetcode.com/problems/first-bad-version/
******************************************************************************/
// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
	int firstBadVersion(int n) {
		int low=1, high=n;
		while (low <= high) {
			int mid=low+(high-low)/2;
			isBadVersion(mid)
			? (high = mid - 1)
			: (low = mid + 1);
		}
		return low;
	}
};

