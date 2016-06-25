class Solution {
private:
    bool overflow(int h, int l) {
        int H=INT_MAX/10, L=INT_MAX%10;
        return (h > H) || (h==H && l>L);
    }
public:
    int reverse(int x) {
        if (INT_MIN == x) return 0;
        int y = abs(x), z = 0;
        for (; y > 0; y /= 10) {
            if (overflow(z, y%10)) {
                z = 0; break;
            }
            z = z * 10 + y % 10;
        }
        z = x < 0 ? -z : z;
        return z;
    }
};
