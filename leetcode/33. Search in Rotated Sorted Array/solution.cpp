class Solution {
public:
    int search(vector<int>& nums, int target) {
        int len = nums.size();
        int low=0, high=len-1, mid;
        while (low+1 < high) {
            mid = (low+high)/2;
            if (nums[mid]>=nums[low]) {
                low = mid;
            } else {
                high = mid;
            }
        }
        int ret = bs(nums, target, 0, low);
        if (-1 == ret) {
            ret = bs(nums, target, high, len-1);
        }
        return ret;
    }
    int bs(vector<int>& nums, int target, int low, int high) {
        while (low <= high) {
            int mid = (low+high)/2;
            if (nums[mid]>target) {
                high = mid - 1; continue;
            }
            if (nums[mid]<target) {
                low = mid + 1; continue;
            }
            return mid;
        }
        return -1;
    }
};
