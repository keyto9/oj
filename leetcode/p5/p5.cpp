/******************************************************************************
Copyright (C), 2015, dploop
FileName: p5.cpp
Author: dploop
Date: 2015/10/28
Description: https://leetcode.com/problems/longest-palindromic-substring/
******************************************************************************/
class Solution {
private:
	bool equal(string &T, int n, int x, int y) {
		if (x < 0 || x > 2*n) return false;
		if (y < 0 || y > 2*n) return false;
		int ox = x&1, oy = y&1;
		return ((ox && oy)
		? T[x/2]==T[y/2] : !(ox^oy));
	}
public:
	string longestPalindrome(string &T) {
		int n=T.length(); vector<int> P(2*n, 0);
		int C = 0, R = 0, MC = 0, MR = 0;
		for (int i = 1; i < 2*n; ++i) {
			int K = 0; if (i < R) {
				K = min(R-i, P[2*C-i]);
			}
			for (; equal(T, n, i-K-1, i+K+1); ) {
				++K;
			}
			if (i + K > R) {
				C = i; R = i + K;
			}
			if (MR - MC < K) {
				MC = C; MR = R;
			}
			P[i] = K;
		}
		return T.substr((2*MC-MR)/2, MR-MC);
	}
};

