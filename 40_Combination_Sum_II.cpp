class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ret;
        vector<int> tmpRet;
        map<int, int> count;
        int cnt=1, i;
        sort(candidates.begin(), candidates.end());
        for(i=0;i<candidates.size();++i){
            if(i>0){
                if(candidates[i]==candidates[i-1]) ++cnt;
                else{
                    count.insert(pair<int,int>(candidates[i-1],cnt));
                    cnt=1;
                }
            }
        }
        count.insert(pair<int,int>(candidates[i-1],cnt));
        auto iter = unique(candidates.begin(), candidates.end());
        candidates.erase(iter, candidates.end());
        helper(0, ret, candidates, target, tmpRet, count);
        return ret;
    }
    void helper(int begin, vector<vector<int>> &ret, vector<int> &candidates, int target, vector<int> tmpRet, map<int, int> &count){
        int tmpval;
        for(int i=0;begin<candidates.size() && i<count[candidates[begin]]+1 && (tmpval=candidates[begin]*i)<=target;++i){
            if(i>0) tmpRet.push_back(candidates[begin]);
            if(tmpval == target) ret.push_back(tmpRet);
            else helper(begin+1, ret, candidates, target-tmpval, tmpRet, count);
        }
    }
};

//Solution 2
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ret;
        vector<int> tmpRet;
        sort(candidates.begin(),candidates.end());
        csHelper(0,ret,candidates,target,tmpRet);
        return ret;
    }
    void csHelper(int begin, vector<vector<int>> &ret, vector<int> &candidates, int target, vector<int> tmpRet){
        if(!target){
            ret.push_back(tmpRet);
            return;
        }
        for(int i=begin;i<candidates.size()&&candidates[i]<=target;++i){
            if(i>begin&&candidates[i]==candidates[i-1]) continue;
            tmpRet.push_back(candidates[i]);
            csHelper(i+1,ret,candidates,target-candidates[i],tmpRet);
            tmpRet.pop_back();
        }
    }
};
