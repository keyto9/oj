/******************************************************************************
Copyright (C), 2015, dploop
FileName: p5.cpp
Author: dploop
Date: 2015/10/28
Description: https://leetcode.com/problems/longest-palindromic-substring/
******************************************************************************/
class Solution {
private:
	bool eq(string &T, int n, int x, int y) {
		if (x < 0 || x > n) return false;
		if (y < 0 || y > n) return false;
		int ox = x & 1, oy = y & 1;
		return ((ox && oy)
			? T[x/2]==T[y/2] : !(ox^oy));
	}
public:
	string longestPalindrome(string &T) {
		int n = 2*T.length(); vector<int> P(n);
		int C = 0, R = 0, MC = 0, MR = 0, K = 0;
		for (int i = 1; i < n; ++i) {
			if (i < R) {K = min(R-i,P[2*C-i]);}
			for (; eq(T,n,i-K-1,i+K+1); ++K);
			if (i + K > R) {C = i; R = i + K;}
			if (MR - MC < K) {MC = C; MR = R;}
			P[i] = K; K = 0;
		}
		return T.substr((2*MC-MR)/2, MR-MC);
	}
};

