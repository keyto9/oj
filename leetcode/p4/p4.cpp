/******************************************************************************
Copyright (C), 2015, dploop
FileName: p4.cpp
Author: dploop
Date: 2015/10/28
Description: https://leetcode.com/problems/median-of-two-sorted-arrays/
******************************************************************************/
class Solution {
public:
	double findMedianSortedArrays(vector<int> &A, vector<int> &B) {
		int m = A.size(), n = B.size();
		if (m <= n) {
			return fuck(&A[0], m, &B[0], n);
		}
		else {
			return fuck(&B[0], n, &A[0], m);
		}
	}
	double fuck(int A[], int m, int B[], int n) {
		if (m <= 0) {
			return (B[(n-1)/2]+B[n/2]) / 2.0;
		}
		if (m <= 2) {
			int C[100], l = 0, x = n/2-1, y = (n+1)/2;
			if (n&1) C[l++] = B[n/2];
			for (int i = 0; i <= m; ++i) {
				if (0<=i   && i  <m) C[l++] = A[i];
				if (0<=x-i && x-i<n) C[l++] = B[x-i];
				if (0<=y+i && y+i<n) C[l++] = B[y+i];
			}
			sort(C, C + l);
			return fuck(A, 0, C, l);
		}
		int p = (m-1) / 2, q = (n-1) / 2;
		if (A[p] < B[q]) {
			return fuck(A+p, m-p, B, n-p);
		}
		else {
			return fuck(A, m-p, B+p, n-p);
		}
	}
};


