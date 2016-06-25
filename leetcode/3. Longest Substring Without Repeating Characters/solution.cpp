class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length(); if (!n) return 0;
        int v[0x100] = {0}, ret = 1;
        for (int i=0, j=0; j < n; ++j) {
            for (++v[s[j]]; v[s[j]]>1; ) {
                --v[s[i]]; ++i;
            }
            ret = max(ret, j-i+1);
        }
        return ret;
    }
};
