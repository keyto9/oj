/******************************************************************************
Copyright (C), 2015, dploop
FileName: p32.cpp
Author: dploop
Date: 2015/11/5
Description: https://leetcode.com/problems/longest-valid-parentheses/
******************************************************************************/
class Solution {
public:
    int longestValidParentheses(string s) {
        int ret=0, len=s.length();
        vector<int> match(len, 0);
        stack<int> mystk;
        for (int i=0; i < len; ++i) {
            if (mystk.empty()) {
                mystk.push(i);
            } else {
                int j = mystk.top();
                if ('('==s[j] && ')'==s[i]) {
                    mystk.pop();
                    match[j]=match[i]=1;
                } else {
                    mystk.push(i);
                }
            }
        }
        int tmp = 0;
        for (int i=0; i < len; ++i) {
            if (match[i]) {
                ret = max(ret, ++tmp);
            } else {
                tmp = 0;
            }
        }
        return ret;
    }
};

