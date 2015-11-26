/******************************************************************************
Copyright (C), 2015, dploop
FileName: p310.cpp
Author: dploop
Date: 2015/11/26
Description: https://leetcode.com/problems/minimum-height-trees/
******************************************************************************/
class Solution {
public:
	vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
		unordered_set<int> sets;
		for (int i=0; i < n; ++i) {
			sets.insert(i);
		}
		vector<unordered_set<int>> graph(n);
		for (auto e : edges) {
			int x=e.first, y=e.second;
			graph[x].insert(y);
			graph[y].insert(x);
		}
		vector<int> curr, next;
		for (int i=0; i < n; ++i) {
			if (graph[i].size() == 1) {
				curr.push_back(i);
			}
		}
		for (; sets.size() > 2; ) {
			for (auto i : curr) {
				sets.erase(i);
				int j=*(graph[i].begin());
				graph[i].erase(j);
				graph[j].erase(i);
				if (graph[j].size() == 1) {
				    next.push_back(j);
				}
			}
			curr = next; next.clear();
		}
		vector<int> ret(sets.begin(), sets.end());
		sort(ret.begin(), ret.end());
		return ret;
	}
};

