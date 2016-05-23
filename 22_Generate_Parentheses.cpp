class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        gpHelper(n, n, "", ret);
        return ret;
    }
    void gpHelper(int left, int right, string s, vector<string> &ret){
        if(left==0&&right==0)
            ret.push_back(s);
        if(left>0)
            gpHelper(left-1, right, s+"(", ret);
        if(left<right)
            gpHelper(left, right-1, s+")", ret);
    }
};
