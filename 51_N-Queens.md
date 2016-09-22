#51. N-Queens
##Question
The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

For example,
There exist two distinct solutions to the 4-queens puzzle:
```
[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
```
##Analysis
* Backtracking
* 另一种快速解法， Use flag vectors as bitmask, 4ms 【[参考链接](https://discuss.leetcode.com/topic/13617/accepted-4ms-c-solution-use-backtracking-and-bitmask-easy-understand)】

##Solution 1 (6ms)
```
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> temp(n, string(n, '.'));
        helper(res, temp, 0, n);
        return res;
    }
    void helper(vector<vector<string>> &res, vector<string> &temp, int row, int n){
        if(row == n){
            res.push_back(temp);
            return;
        }
        for(int i=0;i<n;++i){
            if(isvalid(temp, row, i, n)){
                temp[row][i] = 'Q';
                helper(res, temp, row+1, n);
                temp[row][i] = '.';
            }
        }
    }
    bool isvalid(vector<string> &temp, int row, int column, int n){
        for(int i=row;i>=0;--i)
            if(temp[i][column]=='Q') return false;
        for(int i=row-1,j=column+1;i>=0&&j<n;--i,++j)
            if(temp[i][j]=='Q') return false;
        for(int i=row-1,j=column-1;i>=0&&j>=0;--i,--j)
            if(temp[i][j]=='Q') return false;
        return true;
    }
};
```
##Solution 2(4ms)
```
/**    | | |                / / /             \ \ \
  *    O O O               O O O               O O O
  *    | | |              / / / /             \ \ \ \
  *    O O O               O O O               O O O
  *    | | |              / / / /             \ \ \ \ 
  *    O O O               O O O               O O O
  *    | | |              / / /                 \ \ \
  *   3 columns        5 45° diagonals     5 135° diagonals    (when n is 3)
  */
class Solution {
public:
    std::vector<std::vector<std::string> > solveNQueens(int n) {
        std::vector<std::vector<std::string> > res;
        std::vector<std::string> nQueens(n, std::string(n, '.'));
        std::vector<int> flag_col(n, 1), flag_45(2 * n - 1, 1), flag_135(2 * n - 1, 1);
        solveNQueens(res, nQueens, flag_col, flag_45, flag_135, 0, n);
        return res;
    }
private:
    void solveNQueens(std::vector<std::vector<std::string> > &res, std::vector<std::string> &nQueens, std::vector<int> &flag_col, std::vector<int> &flag_45, std::vector<int> &flag_135, int row, int &n) {
        if (row == n) {
            res.push_back(nQueens);
            return;
        }
        for (int col = 0; col != n; ++col)
            if (flag_col[col] && flag_45[row + col] && flag_135[n - 1 + col - row]) {
                flag_col[col] = flag_45[row + col] = flag_135[n - 1 + col - row] = 0;
                nQueens[row][col] = 'Q';
                solveNQueens(res, nQueens, flag_col, flag_45, flag_135, row + 1, n);
                nQueens[row][col] = '.';
                flag_col[col] = flag_45[row + col] = flag_135[n - 1 + col - row] = 1;
            }
    }
};
```