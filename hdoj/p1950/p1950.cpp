/******************************************************************************
Copyright (C), 2015, dploop
FileName: p1950.cpp
Author: dploop
Date: 2015/11/7
Description: http://acm.hdu.edu.cn/showproblem.php?pid=1950
******************************************************************************/
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 40010;

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
		ans[low] = tmp;
		m = max(m, low+1);
	}
}

int main()
{
	static int arr[MAXN], n;
	static int ans[MAXN], m;
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i=0; i < n; ++i) {
			scanf("%d", &arr[i]);
		}
		lis(arr, n, ans, m);
		printf("%d\n", m);
	}
	return 0;
}

