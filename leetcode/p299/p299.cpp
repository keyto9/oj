/******************************************************************************
Copyright (C), 2015, dploop
FileName: p299.cpp
Author: dploop
Date: 2015/11/5
Description: https://leetcode.com/problems/bulls-and-cows/
******************************************************************************/
class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls=0, cows=0, len=secret.length();
        vector<int> bc(256, 0);
        for (int i=0; i < len; ++i) {
            if (secret[i] == guess[i]) {
                ++bulls;
            } else {
                ++bc[secret[i]];
            }
        }
        for (int i=0; i < len; ++i) {
            if (secret[i] != guess[i]) {
                if (--bc[guess[i]] >= 0) {
                    ++cows;
                }
            }
        }
        char ret[50];
        sprintf(ret, "%dA%dB", bulls, cows);
        return ret;
    }
};

