/******************************************************************************
Copyright (C), 2015, dploop
FileName: p135.cpp
Author: dploop
Date: 2015/11/5
Description: https://leetcode.com/problems/candy/
******************************************************************************/
typedef pair<int, int> pii;

class Solution {
public:
    int candy(vector<int> &ratings) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int n = ratings.size(); if (1 == n) return 1;
        
        priority_queue <pii, vector<pii>, greater<pii> > PQ;
        for (int idx = 0; idx < n; idx++)
            PQ.push(make_pair(ratings[idx], idx));
            
        int sum = 0;
        vector<int> candy(n, 0);
        
        while (!PQ.empty()) {
            pii temp = PQ.top(); PQ.pop();
            int rt = temp.first, idx = temp.second;
            
            int howmany = 1;
            if (idx + 1 < n && rt > ratings[idx + 1]) howmany = max(howmany, candy[idx + 1] + 1);
            if (idx - 1 >=0 && rt > ratings[idx - 1]) howmany = max(howmany, candy[idx - 1] + 1);
            
            sum += candy[idx] = howmany;
        }
        return sum;
    }
};

