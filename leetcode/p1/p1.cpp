/******************************************************************************
Copyright (C), 2015, dploop
FileName: p1.cpp
Author: dploop
Date: 2015/10/28
Description: https://leetcode.com/problems/two-sum/
******************************************************************************/
class Solution {
private:
	typedef std::pair<int, int> PII;
public:
	vector<int> twoSum(vector<int> &numbers, int target) {
		int n=numbers.size(); std::vector<PII> v;
		for (int i = 0; i < n; ++i) {
			v.push_back(std::make_pair(numbers[i], i+1));
		}
		sort(v.begin(), v.end());
		int p=0, q=n-1; vector<int> ret(2, 0);
		for (; ; ) {
			int tmp = v[p].first + v[q].first;
			if (tmp > target) {
				--q; continue;
			}
			if (tmp < target) {
				++p; continue;
			}
			ret[0] = min(v[p].second, v[q].second);
			ret[1] = max(v[p].second, v[q].second);
			break;
		}
		return ret;
	}
};

