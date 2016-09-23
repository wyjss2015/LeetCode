#37. Sudoku Solver
##Question
Write a program to solve a Sudoku puzzle by filling the empty cells.

Empty cells are indicated by the character '.'.

You may assume that there will be only one unique solution.

##Analysis
* 本质上还是backtracking
* 原来有元素的位置只有一种情况，没有元素的位置可以有9种情况。

##Solution
```
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        vector<int> record(81,0);
        vector<int> row(9, 0);
        vector<int> column(9, 0);
        vector<int> unit(9, 0);
        for(int i=0; i<9; ++i)
            for(int j=0;j<9;++j)
                if(board[i][j]!='.'){
                    record[i*9+j] = 1;
                    row[i] += (1<<(board[i][j]-'0'));
                    column[j] += (1<<(board[i][j]-'0'));
                    unit[i/3*3+j/3] += (1<<(board[i][j]-'0'));
                }
        int flag = 0;
        helper(board, record, row, column, unit, 0, flag);
    }
    void helper(vector<vector<char>>& board, vector<int>& record, vector<int>& row, vector<int>& column, vector<int>& unit, int n, int& flag){
        if(n==81){
            flag = 1;
            return;
        }
        if(flag == 1) return;
        if(record[n] == 1) helper(board, record, row, column, unit, n+1, flag);
        else{
            for(int i=1;i<10;++i){
                if(isvalid(row, column, unit, n, i)){
                    int r = n/9;
                    int c = n%9;
                    row[r] += (1<<i);
                    column[c] += (1<<i);
                    unit[r/3*3+c/3] += (1<<i);
                    board[r][c] = '0'+i;
                    helper(board, record, row, column, unit, n+1, flag);
                    if(flag == 1) return;
                    row[r] -= (1<<i);
                    column[c] -= (1<<i);
                    unit[r/3*3+c/3] -= (1<<i);
                }
            }
        }
    }
    bool isvalid(vector<int>& row, vector<int>& column, vector<int>& unit, int n, int x){
        int temp = 1<<x;
        int r = n/9;
        int c = n%9;
        if(!(temp&row[r])&&!(temp&column[c])&&!(temp&unit[r/3*3+c/3]))
            return true;
        return false;
    }
};
```