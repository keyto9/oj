/******************************************************************************
Copyright (C), 2015, dploop
FileName: p1533.cpp
Author: dploop
Date: 2015/11/6
Description: http://ac.jobdu.com/problem.php?pid=1533
******************************************************************************/
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 100010;

void lis(int arr[], int n, int ans[], int &m) {
	m = 0;
	for (int i=0; i < n; ++i) {
		int tmp=arr[i], mid;
		int low=0, high=m-1;
		for (; low <= high; ) {
			mid = (low+high)/2;
			if (ans[mid] >= tmp) {
				high = mid - 1;
			} else {
				low  = mid + 1;
			}
		}
		if (low>=m || tmp<ans[low]) {
			ans[low] = tmp;
			m = max(m, low+1);
		}
	}
}

int main()
{
	static int arr[MAXN], n;
	static int ans[MAXN], m;
	for (; EOF!=scanf("%d", &n); ) {
		for (int i=0; i < n; ++i) {
			scanf("%d", &arr[i]);
		}
		lis(arr, n, ans, m);
		printf("%d\n", m);
	}
	return 0;
}

