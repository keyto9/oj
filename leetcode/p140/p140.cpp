/******************************************************************************
Copyright (C), 2015, dploop
FileName: p140.cpp
Author: dploop
Date: 2015/11/5
Description: https://leetcode.com/problems/word-break-ii/
******************************************************************************/
const int MAXN = 1000;

bool mp[MAXN][MAXN];
bool bk[MAXN];

void preProcess(string &s, unordered_set<string> &dict) {
        // to get the mp[][], nr[]
    int n = s.length();

    memset(mp, false, sizeof(mp));
    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++)
            if (dict.find(s.substr(i, j - i + 1)) != dict.end())
                mp[i][j] = true;

    memset (bk, false, sizeof(bk));
}

void dfs(string &s, int pos, string v, vector<string> &ret) {

    int n = s.length();
    if (n == pos) {ret.push_back(v); return;}

    bool mayBk = true;
    for (int k = 0; pos + k < n; k++) {
        if (true == mp[pos][pos + k] && false == bk[pos + k + 1]) {
            mayBk = false;
            string nv = v + ("" == v ? "" : " ") + s.substr(pos, k + 1);
            dfs(s, pos + k + 1, nv, ret);
        }
    }
    bk[pos] = mayBk;
}

class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        preProcess(s, dict);

        vector<string> ret;
        dfs(s, 0, "", ret);
        return ret;
    }
};


