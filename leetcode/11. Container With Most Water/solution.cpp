class Solution {
public:
    int maxArea(vector<int> &h) {
        int ret=0, low=0, high=h.size()-1;
        for (; low < high; ) {
            if (h[low] < h[high]) {
                ret = max(ret, (high-low)*h[low]);
                ++low;
            }
            else {
                ret = max(ret, (high-low)*h[high]);
                --high;
            }
        }
        return ret;
    }
};
