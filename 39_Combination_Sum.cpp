//84ms
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ret;
        vector<int> tmpRet;
        sort(candidates.begin(), candidates.end());
        helper(0,candidates,target,ret,tmpRet);
        return ret;
    }
    void helper(int begin, vector<int>& candidates, int target, vector<vector<int>> &ret, vector<int> tmpRet){
        int tmpval;
        for(int i=0;begin<candidates.size()&&(tmpval=candidates[begin]*i)<=target;++i){
            if(i>0)
                tmpRet.push_back(candidates[begin]);
            if(tmpval==target)
                ret.push_back(tmpRet);
            else
                helper(begin+1,candidates,target-tmpval,ret,tmpRet);
        }
    }
};


//Solution 2  16ms
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ret;
        vector<int> tmpRet;
        sort(candidates.begin(), candidates.end());
        csHelper(candidates, target, ret, tmpRet, 0);
        return ret;
    }
    void csHelper(vector<int>& candidates, int target, vector<vector<int>> &ret, vector<int> &tmpRet, int begin){
        if(target == 0){
            ret.push_back(tmpRet);
            return;
        }
        for(int i=begin;i<candidates.size()&&candidates[i]<=target;++i){
            tmpRet.push_back(candidates[i]);
            csHelper(candidates, target-candidates[i], ret, tmpRet, i);
            tmpRet.pop_back();
        }
    }
};
