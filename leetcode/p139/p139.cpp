/******************************************************************************
Copyright (C), 2015, dploop
FileName: p139.cpp
Author: dploop
Date: 2015/11/5
Description: https://leetcode.com/problems/word-break/
******************************************************************************/
const int MAXN = 1000;

bool mp[MAXN][MAXN];
bool rt[MAXN];

void preProcess(string &s, unordered_set<string> &dict) {
        // to get the mp[][], nr[]
    int n = s.length();

    memset(mp, false, sizeof(mp));
    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++)
            if (dict.find(s.substr(i, j - i + 1)) != dict.end())
                mp[i][j] = true;

    memset (rt, false, sizeof(rt));
}

class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        preProcess(s, dict);

        int n = s.length(); rt[0] = true;
        for (int i = 0; i < n; i++) if (true == rt[i])
            for (int j = i; j < n; j++) if (true == mp[i][j])
                rt[j + 1] = true;

        return rt[n];
    }
};


