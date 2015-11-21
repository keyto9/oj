/******************************************************************************
Copyright (C), 2015, dploop
FileName: p1500.cpp
Author: dploop
Date: 2015/11/6
Description: http://ac.jobdu.com/problem.php?pid=1500
******************************************************************************/
#include <cstdio>

void longest_increasing_subsequence_left(
		  int array[], int array_size
		, int tail[],  int len_left[]
		// , int prev[]
								) {
	int tail_size = 0;
	// memset(prev, 0xff, array_size*sizeof(int));
	for (int index=0; index < array_size; ++index) {
		int low=0, high=tail_size-1; for (; low <= high; ) {
			int mid = low + (high - low) / 2;
			// '<' '<=' '>' '>='  ---- four cases
			( array[ tail[mid] ] < array[index] )
			? (low = mid + 1) : (high = mid - 1);
		}
		tail[low] = index; len_left[index] = low;
		(tail_size<=low) && (tail_size = low + 1);
		// (low > 0) && (prev[index] = tail[low-1]);
	}
}

void longest_increasing_subsequence_right(
		  int array[], int array_size
		, int tail[],  int len_right[]
		// , int prev[]
								) {
	int tail_size = 0;
	// memset(prev, 0xff, array_size*sizeof(int));
	for (int index=array_size-1; index >= 0; --index) {
		int low=0, high=tail_size-1; for (; low <= high; ) {
			int mid = low + (high - low) / 2;
			// '<' '<=' '>' '>='  ---- four cases
			( array[ tail[mid] ] < array[index] )
			? (low = mid + 1) : (high = mid - 1);
		}
		tail[low] = index; len_right[index] = low;
		(tail_size<=low) && (tail_size = low + 1);
		// (low > 0) && (prev[index] = tail[low-1]);
	}
}

int main()
{
	const int MAXN = 1000010;
	static int array[MAXN], array_size;
	static int tail[MAXN], len_left[MAXN], len_right[MAXN];
	for (; EOF!=scanf("%d", &array_size); ) {
		for (int i=0; i < array_size; ++i) {
			scanf("%d", &array[i]);
		}
		longest_increasing_subsequence_left(
			array, array_size, tail, len_left);
		longest_increasing_subsequence_right(
			array, array_size, tail, len_right);
		int max_len = 0;
		for (int i=0; i < array_size; ++i) {
			int tmp = len_left[i]+len_right[i]+1;
			(max_len < tmp) && (max_len = tmp);
		}
		printf("%d\n", array_size-max_len);
	}
	return 0;
}
