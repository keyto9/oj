class Solution {
public:
    bool isPalindrome(int x) {
        if (x<0 || x && 0==x%10) return false;
        int y = 0; for (; x > y; x /= 10) {
            y = y * 10 + x % 10;
            if (x == y) return true;
        }
        return x == y;
    }
};
