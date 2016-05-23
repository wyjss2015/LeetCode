class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        sort(nums.begin(), nums.end());
        map<int,int> numsMap;
        int i,j;
        int tmp1, tmp2, tmp3;
        int flag;
        if(nums.size()<3) return ret;
        for(int i=0;i<nums.size();++i){
            if(numsMap.count(nums[i])) ++numsMap[nums[i]];
            else numsMap.insert(pair<int,int>(nums[i],1));
        }
        for(i=0;i<nums.size();++i){
            if(i>0&&nums[i]==nums[i-1]) continue;
            tmp1 = nums[i];
            for(j=i+1;j<nums.size();++j){
                if(j>i+1&&nums[j]==nums[j-1]) continue;
                tmp2 = nums[j];
                tmp3 = 0-tmp1-tmp2;
                if(tmp3==tmp1) flag=3;				//记录某个值使用次数，修正（[0,0,0] [-1,1,-2,0] [-2,0,1,1,-1]）
                else if(tmp3==tmp2) flag=2;
                else flag=1;
                if(numsMap.count(tmp3)&&tmp3>=tmp2&&numsMap[tmp3]-flag>=0)
                    ret.push_back(vector<int>{tmp1, tmp2, tmp3});
            }
        }
        return ret;
    }
};
