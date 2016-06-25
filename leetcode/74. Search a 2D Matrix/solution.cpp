class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size(), m=0; if (n) m = matrix[0].size();
        int low=0, high=n*m-1;
        for (int low=0, high=n*m-1; low <= high; ) {
            int mid = low + (high - low) / 2;
            int val = matrix[ mid / m ][ mid % m ];
            if (target < val) {high = mid - 1;}
            else if (target > val) {low = mid + 1;}
            else {return true;}
        }
        return false;
    }
};
