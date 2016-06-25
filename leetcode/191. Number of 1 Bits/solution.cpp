class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ret = 0;
        for (; n; ++ret) {
            n ^= n & (-n);
        }
        return ret;
    }
};