class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ret;
        if(numRows==1)
            ret.push_back(vector<int>{1});
        if(numRows>1){
            ret.push_back(vector<int>{1});
            ret.push_back(vector<int>{1,1});
            for(int i=2;i<numRows;++i){
                ret.push_back(vector<int>{1});
                for(vector<int>::size_type j=1;j<ret[i-1].size();++j)
                    ret[i].push_back(ret[i-1][j-1]+ret[i-1][j]);
                ret[i].push_back(1);
            }
        }
        return ret;
    }
};
