/******************************************************************************
Copyright (C), 2015, dploop
FileName: p303.cpp
Author: dploop
Date: 2015/11/25
Description: https://leetcode.com/problems/range-sum-query-immutable/
******************************************************************************/
class NumArray {
private:
	vector<int> sums;
	int sums_size;
	int safeSum(int i) {
		if (i < 0 || sums_size <= i) {
			return 0;
		}
		return sums[i];
	}
public:
	NumArray(vector<int> &nums) {
		sums = nums;
		sums_size = nums.size();
		for (int i=0; i < sums_size; ++i) {
			sums[i] = safeSum(i-1) + nums[i];
		}
	}

	int sumRange(int i, int j) {
		return safeSum(j) - safeSum(i-1);
	}
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);

