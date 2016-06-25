class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int len = nums.size();
        int low=0, high=len-1; while (low <= high) {
            int mid = (low + high) / 2;
            (nums[mid]>=target) ? (high=mid-1) : (low=mid+1);
        }
        return low;
    }
};
