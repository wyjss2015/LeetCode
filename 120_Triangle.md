#120. Triangle
##Question
Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle
```
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
```
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
Note:
Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.

##Analysis
* DP
	1. 将原始问题降解成终点为最底层元素的最短路径，从而可以构造dp子问题如下
	2. 子问题 A[i,j]（表示第i层第j个元素为路径终点的最短路径长度）
	3. return min(A[n,j])

##Solution
```
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        if(m==0) return 0;
        if(m==1) return triangle[0][0];
        vector<int> pre;
        vector<int> cur(1, triangle[0][0]);
        for(int i=1; i<m; ++i){
            pre = vector<int>(cur.begin(), cur.end());
            cur.clear();
            int n = triangle[i].size();
            for(int j=0; j<n; ++j){
                if(j==0) cur.push_back(pre[0]+triangle[i][j]);
                else if(j==n-1) cur.push_back(pre[j-1]+triangle[i][j]);
                else cur.push_back((pre[j-1]>pre[j]?pre[j]:pre[j-1])+triangle[i][j]);
            }
        }
        int min = INT_MAX;
        for(auto &temp: cur)
            if(temp<min) min = temp;
        return min;
    }
};
```