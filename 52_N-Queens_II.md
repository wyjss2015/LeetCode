#52. N-Queens II
##Question
Follow up for N-Queens problem.

Now, instead outputting board configurations, return the total number of distinct solutions.
##Analysis
* 基本同[51_N-Queens.md](52_N-Queens.md)

##Solution
```
class Solution {
public:
    int totalNQueens(int n) {
        int total=0;
        vector<string> temp(n, string(n, '.'));
        helper(total, temp, 0, n);
        return total;
    }
    void helper(int &total, vector<string> &temp, int row, int n){
        if(row == n){
            ++total;
            return;
        }
        for(int i=0;i<n;++i){
            if(isvalid(temp, row, i, n)){
                temp[row][i] = 'Q';
                helper(total, temp, row+1, n);
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