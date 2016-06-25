class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret; int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i=0; i < n; ++i) {
            if (i>0 && nums[i-1]==nums[i]) {continue;}
            for (int j=i+1, k=n-1; j < k; ) {
                if (j>i+1 && nums[j-1]==nums[j]) {++j; continue;}
                if (k<n-1 && nums[k+1]==nums[k]) {--k; continue;}
                if (nums[i]+nums[j]+nums[k] < 0) {++j; continue;}
                if (nums[i]+nums[j]+nums[k] > 0) {--k; continue;}
                ret.push_back(vector<int>({nums[i],nums[j],nums[k]}));
                ++j; --k;
            }
        }
        return ret;
    }
};
