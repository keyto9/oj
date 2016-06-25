class Solution {
public:
    vector<int> countBits(int num) {
        ++num; assert(num >= 0);
        vector<int> ret(num, 0);
        for (int i=1; i < num; ++i) {
            ret[i] = ret[i/2] + i%2;
        }
        return ret;
    }
};
