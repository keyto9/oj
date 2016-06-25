class Solution {
public:
    string convert(string s, int nRows) {  
        if (1 == nRows) return s; string ret = "";
        int len = s.length(), period = 2*(nRows-1);
        for (int k = 0; k < nRows; k++) {
            int idx = k; while (idx < len) {
                ret.push_back(s[idx]); idx += period;
                if (0==k || k==nRows-1) continue;
                int idy = idx - k - k;
                if (idy < len) ret.push_back(s[idy]);
            }
        }
        return ret;
    }
};

