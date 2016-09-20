#279. Perfect Squares
##Question
Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.

For example, given n = 12, return 3 because 12 = 4 + 4 + 4; given n = 13, return 2 because 13 = 4 + 9.

##Analysis
* DP (有点像背包问题)
* 讨论中有人总结了4种方法（DP, static DP, math, BFS）【[链接](https://discuss.leetcode.com/topic/24255/summary-of-4-different-solutions-bfs-dp-static-dp-and-mathematics)】
* BFS
	1. 边表示两点i, j 之间相差一个完美平方数
	2. 从0开始BFS，同时记录level
	3. 当遇到n时返回level
* 我写的BFS超时，可以参考链接的解法

##Solution
```
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1);
        dp[0] = 0;
        dp[1] = 1;
        for(int i=2;i<n+1;++i){
            dp[i] = INT_MAX;
            for(int j=1;j*j<=i;++j)
                if(dp[i]>dp[i-j*j]+1) dp[i] = dp[i-j*j]+1;
        }
        return dp[n];
    }
};
```
