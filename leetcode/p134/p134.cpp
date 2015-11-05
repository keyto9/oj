/******************************************************************************
Copyright (C), 2015, dploop
FileName: p134.cpp
Author: dploop
Date: 2015/11/5
Description: https://leetcode.com/problems/gas-station/
******************************************************************************/
class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int n = gas.size();
        
        int sum = 0, minSum = 0x7fffffff, minIdx = -1;
        for (int i = 0; i < n; i++) {
            sum += gas[i] - cost[i];
            if (minSum >= sum) {
                minSum = sum;
                minIdx = i;
            }
        }
        
        return sum >= 0 ? (minIdx + 1) % n : -1;
    }
};
