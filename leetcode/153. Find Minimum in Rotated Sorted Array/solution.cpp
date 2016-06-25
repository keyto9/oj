class Solution {
public:
    int findMin(vector<int>& nums) {
        int len = nums.size(); if (len <= 0) return 0;
        int low=0, high=len-1; while (low+1<high) {
            int mid = low + (high - low) / 2;
            (nums[low]>nums[mid])?(high=mid):(low=mid);
        }
        return min(nums[0], nums[high]);
    }
};