class Solution {
public:
    double findMedianSortedArrays(vector<int> &A, vector<int> &B) {
        int m=A.size(), n=B.size(), imin=0, imax=m-1, i, j;
        if (m > n) {return findMedianSortedArrays(B, A);}
        while (imin <= imax) {
            i = (imin + imax) / 2; j = (m + n + 1) / 2 - i;
            (B[j-1] > A[i]) ? (imin = i+1) : (imax = i-1);
        }
        i = imin; j = (m + n + 1) / 2 - i;
        int lhs=INT_MIN; if (i) lhs=A[i-1]; if (j) lhs=max(lhs, B[j-1]);
        if ((m + n) % 2) {return lhs;}
        int rhs=INT_MAX; if (i<m) rhs=A[i]; if (j<n) rhs=min(rhs, B[j]);
        return (lhs + rhs) / 2.0;
    }
};
