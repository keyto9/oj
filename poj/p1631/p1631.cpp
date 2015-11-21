/******************************************************************************
Copyright (C), 2015, dploop
FileName: p1631.cpp
Author: dploop
Date: 2015/11/22
Description: http://poj.org/problem?id=1631
******************************************************************************/
#include <cstdio>

void longest_increasing_subsequence(
		  int array[], int array_size
		, int tail[],  int &tail_size
		// , int prev[]
								) {
	tail_size = 0;
	// memset(prev, 0xff, array_size*sizeof(int));
	for (int index=0; index < array_size; ++index) {
		int low=0, high=tail_size-1; for (; low <= high; ) {
			int mid = low + (high - low) / 2;
			// '<' '<=' '>' '>='  ---- four cases
			( array[ tail[mid] ] < array[index] )
			? (low = mid + 1) : (high = mid - 1);
		}
		tail[low] = index;
		(tail_size<=low) && (tail_size = low + 1);
		// (low > 0) && (prev[index] = tail[low-1]);
	}
}

int main()
{
	const int MAXN = 40010;
	static int array[MAXN], array_size;
	static int tail[MAXN], tail_size;
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%d", &array_size);
		for (int i=0; i < array_size; ++i) {
			scanf("%d", &array[i]);
		}
		longest_increasing_subsequence(
			array, array_size, tail, tail_size);
		printf("%d\n", tail_size);
	}
	return 0;
}

