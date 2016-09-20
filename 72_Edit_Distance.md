#72. Edit Distance
##Question
Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

a) Insert a character
b) Delete a character
c) Replace a character

##Analysis
* 最佳字符串匹配的变种
* DP

##Solution
```
class Solution {
public:
    int minDistance(string word1, string word2) {
        word1 = " " + word1;
        word2 = " " + word2;
        int n1 = word1.size();
        int n2 = word2.size();
        int dp[n1][n2];
        for(int i=0;i<n1;++i)
            dp[i][0] = i;
        for(int i=0;i<n2;++i)
            dp[0][i] = i;
        for(int i=1;i<n1;++i){
            for(int j=1;j<n2;++j){
                if(word1[i] == word2[j]) dp[i][j] = dp[i-1][j-1];
                else{
                    if(dp[i-1][j-1]<=dp[i][j-1]&&dp[i-1][j-1]<=dp[i-1][j]) dp[i][j] = dp[i-1][j-1]+1;
                    else if(dp[i][j-1]<=dp[i-1][j-1]&&dp[i][j-1]<=dp[i-1][j]) dp[i][j] = dp[i][j-1]+1;
                    else dp[i][j] = dp[i-1][j]+1;
                }
            }
        }
        return dp[n1-1][n2-1];
    }
};
```