/******************************************************************************
Copyright (C), 2016, dploop
FileName: p242.cpp
Author: dploop
Date: 2016/4/21
Description: https://leetcode.com/problems/valid-anagram/
******************************************************************************/
class Solution {
public:
	bool isAnagram(string s, string t) {
		vector<int> count(26, 0);
		for (auto x : s) {
			++count[x-'a'];
		}
		for (auto x : t) {
			--count[x-'a'];
		}
		for (auto x : count) {
			if (x != 0) {
				return false;
			}
		}
		return true;
	}
};

