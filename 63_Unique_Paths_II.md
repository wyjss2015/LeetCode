#62. Unique Paths
##Question
Follow up for "Unique Paths":

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

For example,
There is one obstacle in the middle of a 3x3 grid as illustrated below.
```
[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
```
The total number of unique paths is 2.

Note: m and n will be at most 100.

##analysis
* DP
* 有障碍的位置置0
* 初始化也要注意

##Solution
```
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        int dp[m][n];
        
        int flag = 0;
        for(int i=0;i<m;++i){
            if(flag == 1)
                dp[i][0] = 0;
            else if(obstacleGrid[i][0]==1){
                dp[i][0] = 0;
                flag = 1;
            }else
                dp[i][0] = 1;
        }
        flag = 0;
        for(int i=0;i<n;++i){
            if(flag == 1)
                dp[0][i] = 0;
            else if(obstacleGrid[0][i]==1){
                dp[0][i] = 0;
                flag = 1;
            }else
                dp[0][i] = 1;
        }
        
        for(int i=1;i<m;++i){
            for(int j=1;j<n;++j)
                if(obstacleGrid[i][j]==1) dp[i][j] = 0;
                else dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
        return dp[m-1][n-1];
    }
};
```