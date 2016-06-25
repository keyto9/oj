class Solution {
public:
    bool isMatch(string &T, string &P) {
        int n = T.length(), m = P.length();
        vector<bool> dp(n+1); dp[0] = true;
        for (int i = 0; i < m; ++i) {
            if (i+1<m && '*'==P[i+1]) {
                for (int j = n; j > 0; --j) {
                    for (int k=j; !dp[j]&&k&&('.'==P[i]||T[k-1]==P[i]); ) {
                        dp[j] = dp[k-1]; --k;
                    }
                } ++i;
            } else {
                for (int j = n; j > 0; --j) {
                    dp[j] = dp[j-1] && ('.'==P[i] || T[j-1]==P[i]);
                }
                dp[0] = false;
            }
        }
        return dp[n];
    }
};
