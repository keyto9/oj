class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size(), r = 0;
        for (int i=0; i < n; ++i) {
            r ^= (i+1) ^ nums[i];
        }
        return r;
    }
};
