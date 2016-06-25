class Solution {
public:
    int myAtoi(string str) {
        int len = str.length(), idx = 0;
        while (idx<len && isblank(str[idx])) ++idx;
        if (idx >= len) return 0;
        bool minus = '-' == str[idx];
        if ('-'==str[idx] || '+'==str[idx]) ++idx;
        int64_t sum=0, i_max=INT_MAX, i_min=INT_MIN;
        while (idx<len && isdigit(str[idx])) {
            sum = sum * 10 + str[idx] - '0';
            if (minus && -sum < i_min
            || !minus && sum > i_max) break;
            idx++;
        }
        if (minus && -sum < i_min) return INT_MIN;
        if (!minus && sum > i_max) return INT_MAX;
        return minus ? -int(sum) : int(sum);
    }
};
