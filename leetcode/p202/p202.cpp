/******************************************************************************
Copyright (C), 2016, dploop
FileName: p202.cpp
Author: dploop
Date: 2016/4/22
Description: https://leetcode.com/problems/happy-number/
******************************************************************************/
class Solution {
public:
	bool isHappy(int n) {
		for (; ; ) {
			switch (n) {
				case 1: return true;
				case 4: return false;
				default: n = next(n);
			}
		}
	}
private:
	int next(int n) {
		int ret = 0;
		for (int x; n; n /= 10) {
			x = n%10; ret += x*x;
		}
		return ret;
	}
};

