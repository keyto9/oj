/******************************************************************************
Copyright (C), 2015, dploop
FileName: p301.cpp
Author: dploop
Date: 2015/11/5
Description: https://leetcode.com/problems/remove-invalid-parentheses/
******************************************************************************/
class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        unordered_set<string> set; int max_len=0;
        dfs(set, max_len, "", 0, 0, 0, s, s.length(), -1);
        vector<string> ret;
        for (auto x : set) {
            ret.push_back(x);
        }
        return ret;
    }
    void dfs(unordered_set<string> &set, int &max_len
            , string str, int str_len, int lft, int rht
            , string &ori, int ori_len, int idx) {
        if (lft == rht) {
            if (str_len > max_len) {
                set.clear();
                max_len = str_len;
            }
            if (str_len >= max_len) {
                set.insert(str);
            }
        }
        if (++idx < ori_len) {
            if (ori[idx] == '(') {
                dfs(set, max_len, str+ori[idx], str_len+1, lft+1, rht, ori, ori_len, idx);
            } else
            if (ori[idx] == ')') { if (lft > rht)
                dfs(set, max_len, str+ori[idx], str_len+1, lft, rht+1, ori, ori_len, idx);
            } else {
                dfs(set, max_len, str+ori[idx], str_len+1, lft, rht, ori, ori_len, idx);
            }
            dfs(set, max_len, str, str_len, lft, rht, ori, ori_len, idx);
        }
    }
};

