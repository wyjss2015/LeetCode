class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int hash[10];
        hashClear(hash);
        for(vector<vector<char>>::size_type row=0;row<9;++row){
            for(vector<char>::size_type col=0;col<9;++col){
                if(board[row][col]=='.')
                    continue;
                else{
                    if(hash[board[row][col]-'0']==0)
                        hash[board[row][col]-'0'] = 1;
                    else
                        return false;
                }
            }
            hashClear(hash);
        }
        for(vector<char>::size_type col=0;col<9;++col){
            for(vector<vector<char>>::size_type row=0;row<9;++row){
                if(board[row][col]=='.')
                    continue;
                else{
                    if(hash[board[row][col]-'0']==0)
                        hash[board[row][col]-'0'] = 1;
                    else
                        return false;
                }
            }
            hashClear(hash);
        }
        hashClear(hash);
        for(vector<vector<char>>::size_type i=0;i<3;++i){
            for(vector<char>::size_type j=0;j<3;++j){
                for(vector<vector<char>>::size_type row=0;row<3;++row){
                    for(vector<char>::size_type col=0;col<3;++col){
                        if(board[i*3+row][j*3+col]=='.')
                            continue;
                        else{
                            if(hash[board[i*3+row][j*3+col]-'0']==0)
                                hash[board[i*3+row][j*3+col]-'0'] = 1;
                            else
                                return false;
                        }
                    }
                }
                hashClear(hash);
            }
        }
        return true;
    }
    void hashClear(int *hash){
        for(int i=0;i<10;++i)
            hash[i] = 0;
    }
};
