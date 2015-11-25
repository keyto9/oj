/******************************************************************************
Copyright (C), 2015, dploop
FileName: p301.cpp
Author: dploop
Date: 2015/11/5
Description: https://leetcode.com/problems/remove-invalid-parentheses/
******************************************************************************/
// dfs
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

// bfs
class Solution {
private:
    bool isValid(string s) {
        int lft=0, rht=0;
        for (auto x : s) {
            (x == '(') && (++lft);
            (x == ')') && (++rht);
            if (lft < rht) {
                break;
            }
        }
        return lft == rht;
    }
public:
    vector<string> removeInvalidParentheses(string s) {
        unordered_set<string> sets;
        unordered_set<string> hash;
        queue<string> q; q.push(s);
        hash.insert(s);
        for (int max_len=-1; !q.empty(); ) {
            string e = q.front(); q.pop();
            int elength = e.length();
            if (elength < max_len) {
                break;
            }
            if (isValid(e)) {
                sets.insert(e);
                max_len = elength;
            } else {
                for (int i=0; i < elength; ++i) {
                    string f = e; f.erase(i, 1);
                    if (hash.find(f) == hash.end()) {
                        q.push(f); hash.insert(f);
                    }
                }
            }
        }
        vector<string> ret;
        for (auto x : sets) {
            ret.push_back(x);
        }
        return ret;
    }
};

