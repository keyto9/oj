/******************************************************************************
Copyright (C), 2015, dploop
FileName: p20.cpp
Author: dploop
Date: 2015/10/31
Description: https://leetcode.com/problems/valid-parentheses/
******************************************************************************/
class Solution {
private:
	bool isMatch(char p, char q) {
		return (p=='(' && q==')')
			|| (p=='{' && q=='}')
			|| (p=='[' && q==']');
	}
public:
	bool isValid(string s) {
		stack<char> stk;
		for (auto x : s) {
			if (stk.empty()) {
				stk.push(x);
			}
			else {
				auto y = stk.top();
				if (isMatch(y, x)) {
					stk.pop();
				}
				else {
					stk.push(x);
				}
			}
		}
		return stk.empty();
	}
};

