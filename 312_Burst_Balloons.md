#312. Burst Balloons
##Question
Given n balloons, indexed from 0 to n-1. Each balloon is painted with a number on it represented by array nums. You are asked to burst all the balloons. If the you burst balloon i you will get nums[left] * nums[i] * nums[right] coins. Here left and right are adjacent indices of i. After the burst, the left and right then becomes adjacent.

Find the maximum coins you can collect by bursting the balloons wisely.

Note: 
(1) You may imagine nums[-1] = nums[n] = 1. They are not real therefore you can not burst them.
(2) 0 ≤ n ≤ 500, 0 ≤ nums[i] ≤ 100

Example:

Given [3, 1, 5, 8]

Return 167
```
    nums = [3,1,5,8] --> [3,5,8] -->   [3,8]   -->  [8]  --> []
   coins =  3*1*5      +  3*5*8    +  1*3*8      + 1*8*1   = 167
```

##Analysis
* DP
* 思路上关键点是观察到利用最后一个刺破的气球当切分点，因为最后一个刺破球两边部分不相关
	1. 假如最后一个刺破球i， 利用暴力求解i左边部分需要遍历情况数M，右边N
	2. 所有暴力求解仅1步中的情况需要M*N
	3. 观察到M，N独立，所以利用DP分别求出M最优和N中最优，就可以缩减为M+N
	4. 上述的M*N 和M+N都是递归定义的，所以利用独立性进行DP设计可以大大减少重复计算
* 编程上关键点是子结构中左右边界不刺破
* 总体上，不管是思路还是编程上，以目前的水平都很难想到。
* 【[参考链接](https://discuss.leetcode.com/topic/30746/share-some-analysis-and-explanations/2)】

##Solution
```
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+2, vector<int>(n+2, 0));
        for(int i=1;i<n+1;++i) dp[i][i] = nums[i-1];
        dp[0][0] = dp[n+1][n+1] = 1;
        for(int k=2;k<n+2;++k){
            for(int left=0;left<n-k+2;++left){
                int right = left+k;
                dp[left][right] = 0;
                for(int j=left+1;j<left+k;++j){
                    if(dp[left][right]<dp[left][j]+dp[j][right]+dp[j][j]*dp[left][left]*dp[right][right])
                        dp[left][right] = dp[left][j]+dp[j][right]+dp[j][j]*dp[left][left]*dp[right][right];
                }
            }
        }
        return dp[0][n+1];
    }
};
```