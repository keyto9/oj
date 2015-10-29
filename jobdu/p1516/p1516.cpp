/******************************************************************************
Copyright (C), 2015, dploop
FileName: p1516.cpp
Author: dploop
Date: 2015/10/29
Description: http://ac.jobdu.com/problem.php?pid=1516
******************************************************************************/
#include <cstdio>
#include <algorithm>
using namespace std;

bool pred(int x)
{
	return x&1;
}

int main()
{
	int n; scanf("%d", &n);
	int *arr = new int[n];
	for (int i=0; i<n; ++i) {
		scanf("%d", &arr[i]);
	}
	stable_partition(arr, arr+n, pred);
	for (int i=0; i < n; ++i) {
		if (i > 0) printf(" ");
		printf("%d", arr[i]);
	}
	delete[] arr;
	return 0;
}

