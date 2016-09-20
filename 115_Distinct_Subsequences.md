#115. Distinct Subsequences
##Question
Given a string S and a string T, count the number of distinct subsequences of T in S.

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).

Here is an example:
S = "rabbbit", T = "rabbit"

Return 3.

##Analysis
* DP

##Solution
```
class Solution {
public:
    int numDistinct(string s, string t) {
        if(t.empty()) return 0;
        if(t.size()>s.size()) return 0;
        int m = s.size();
        int n = t.size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        int cnt = 0;
        for(int i=0;i<m;++i){
            if(s[i]==t[0]) ++cnt;
            dp[i][0] = cnt;
        }

        for(int i=1;i<n;++i){
            cnt = 0;
            for(int j=i;j<m;++j){
                if(s[j]==t[i]) cnt += dp[j-1][i-1];
                dp[j][i] = cnt;
            }
        }
        return dp[m-1][n-1];
    }
};
```