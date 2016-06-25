class Solution {
public:
    int mySqrt(int x) {
        return (int) (1 / Q_rsqrt(x));
    }
    double Q_rsqrt(double x)
    {
        int64_t i = * (int64_t*) &x;
        i = 0x5fe6eb50c7aa19f9 - i/2;
        double y = * (double*) &i;
        y = y * (3 - x*y*y) * 0.5;
        y = y * (3 - x*y*y) * 0.5;
        y = y * (3 - x*y*y) * 0.5;
        return y;
    }
};
