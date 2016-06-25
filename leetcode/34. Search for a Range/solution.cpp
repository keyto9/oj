class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ret;
        ret.push_back(search_great_equal(nums, target));
        ret.push_back(search_less_equal(nums, target));
        return ret;
    }
    int search_great_equal(vector<int> &nums, int target) {
        int ret = -1, len = nums.size();
        int low=0, high=len-1; while (low <= high) {
            int mid = (low + high) / 2;
            (nums[mid]>=target) ? (high=mid-1) : (low=mid+1);
        }
        if (low<len && nums[low]==target) {ret = low;}
        return ret;
    }
    int search_less_equal(vector<int> &nums, int target) {
        int ret = -1, len = nums.size();
        int low=0, high=len-1; while (low <= high) {
            int mid = (low + high) / 2;
            (nums[mid]<=target) ? (low=mid+1) : (high=mid-1);
        }
        if (high>=0 && nums[high]==target) {ret = high;}
        return ret;
    }
};
