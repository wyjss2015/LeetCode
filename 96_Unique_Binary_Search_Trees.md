#96. Unique Binary Search Trees

##Question
Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's.
```
 1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
```

##Analysis
* DP

##Solution
```
class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1);
        dp[0] = 0;
        dp[1] = 1;
        for(int i=2;i<n+1;++i){
            int sum = 0;
            sum += (2*dp[i-1]);
            for(int j=2;j<i;++j)
                sum += (dp[j-1]*dp[i-j]);
            dp[i] = sum;
        }
        return dp[n];
    }
};
```