class Solution {
public:
    int romanToInt(string s) {
        int c2n[256]; c2n['I']=1;
        c2n['V']=5; c2n['X']=10;
        c2n['L']=50; c2n['C']=100;
        c2n['D']=500; c2n['M']=1000;
        int ret=0, len=s.length();
        for (int i=0; i < len; ++i) {
            int add = c2n[s[i]];
            if (i+1<len && c2n[s[i]]<c2n[s[i+1]]) {
                add = -add;
            }
            ret += add;
        }
        return ret;
    }
};
