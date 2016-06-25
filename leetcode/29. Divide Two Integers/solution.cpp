class Solution {
public:
    int divide(int dividend, int divisor) {
        if (INT_MIN==dividend && -1==divisor
            || 0 == divisor) return INT_MAX;
        return dividend / divisor;
    }
};
