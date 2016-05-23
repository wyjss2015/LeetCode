class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ret, pre;
        if(rowIndex == 0)
            ret = vector<int>{1};
        if(rowIndex == 1){
            ret = vector<int>{1,1};
        }else{
            pre = vector<int>{1,1};
            for(int i=2;i<=rowIndex;++i){
                ret = vector<int>{1};
                for(vector<int>::size_type j=1;j<pre.size();++j)
                    ret.push_back(pre[j-1]+pre[j]);
                ret.push_back(1);
                pre = ret;
            }
        }
        return ret;
    }
};
