/******************************************************************************
Copyright (C), 2015, dploop
FileName: p1131.cpp
Author: dploop
Date: 2015/11/6
Description: http://ac.jobdu.com/problem.php?pid=1131
******************************************************************************/
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 1000010;

void lis_inc(int arr[], int n, int ans[], int inc[]) {
	int m = 0;
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
		inc[i] = low;
		ans[low] = tmp;
		m = max(m, low+1);
	}
}

void lis_dec(int arr[], int n, int ans[], int dec[]) {
	int m = 0;
	for (int i=n-1; i>=0; --i) {
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
		dec[i] = low;
		ans[low] = tmp;
		m = max(m, low+1);
	}
}

int main()
{
	static int arr[MAXN], n;
	static int ans[MAXN], inc[MAXN], dec[MAXN];
	for (; EOF!=scanf("%d", &n); ) {
		for (int i=0; i < n; ++i) {
			scanf("%d", &arr[i]);
		}
		lis_inc(arr, n, ans, inc);
		// for (int i=0; i < n; ++i) {
		// 	printf("%d ", inc[i]);
		// }
		// puts("");
		lis_dec(arr, n, ans, dec);
		// for (int i=0; i < n; ++i) {
		// 	printf("%d ", dec[i]);
		// }
		// puts("");
		int max_len = 0;
		for (int i=0; i < n; ++i) {
			int tmp = inc[i]+dec[i]+1;
			max_len = max(max_len, tmp);
		}
		printf("%d\n", n-max_len);
	}
	return 0;
}

