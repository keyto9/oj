/******************************************************************************
Copyright (C), 2015, dploop
FileName: p17.cpp
Author: dploop
Date: 2015/10/31
Description: https://leetcode.com/problems/letter-combinations-of-a-phone-number/
******************************************************************************/
class Solution {
private:
	void cartesianProduct(vector<string> &ret, string foo
								, vector<string> &alpha) {
		int len=foo.length(), size=alpha.size();
		if (len >= size) {
			ret.push_back(foo); return;
		}
		string sigma = alpha[len];
		for (auto x : sigma) {
			string bar=foo; bar.push_back(x);
			cartesianProduct(ret, bar, alpha);
		}
	}
public:
	vector<string> letterCombinations(string digits) {
		vector<string> ret, alpha;
		if (digits.length() == 0) return ret;
		string n2s[10] = {" ","","abc","def","ghi","jkl"
							,"mno","pqrs","tuv","wxyz"};
		for (auto x : digits) {
			alpha.push_back(n2s[x-'0']);
		}
		cartesianProduct(ret, "", alpha);
		return ret;
	}
};

