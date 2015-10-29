/******************************************************************************
Copyright (C), 2015, dploop
FileName: p8.cpp
Author: dploop
Date: 2015/10/29
Description: https://leetcode.com/problems/string-to-integer-atoi/
******************************************************************************/
class Solution {
public:
	int myAtoi(string &str) {
		int idx = 0; while (str[idx] == ' ') idx++;
		bool minus = (str[idx] == '-');
		if ('-' == str[idx] || '+' == str[idx]) idx++;
		long long sum = 0, i_max = INT_MAX, i_min = INT_MIN;
		while (isdigit(str[idx])) {
			sum = sum * 10 + str[idx] - '0';
			if (minus && -sum < i_min
			|| !minus && sum > i_max) break;
			idx++;
		}
		if (minus && -sum < i_min) return INT_MIN;
		if (!minus && sum > i_max) return INT_MAX;
		return minus ? -int(sum) : int(sum);
	}
};
