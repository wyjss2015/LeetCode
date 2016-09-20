#240. Search a 2D Matrix II
##Question
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.
For example,

Consider the following matrix:
```
[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]
```
Given target = 5, return true.

Given target = 20, return false.

##Analysis
* 分治，类似二分查找，关键得找到比较的点（右上角）

##Solution
```
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size()==0) return false;
        return helper(matrix, 0, matrix[0].size()-1, target);
    }
    bool helper(vector<vector<int>>& matrix, int r, int c, int target){
        if(r>matrix.size()-1||c<0) return false;
        int temp = matrix[r][c];
        if(temp == target) return true;
        else if(temp > target) return helper(matrix, r, c-1, target);
        else return helper(matrix, r+1, c, target);
    }
};
```