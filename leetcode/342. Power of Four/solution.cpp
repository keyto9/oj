class Solution {
public:
    bool isPowerOfFour(int num) {
        bool isPowerOfTwo = (num > 0)
            && (num == (num&(-num)));
        return isPowerOfTwo
                && (num & 0x55555555);
    }
};
