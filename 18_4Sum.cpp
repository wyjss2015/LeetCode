class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int tmp;
        int i,j,k,l;
        vector<vector<int>> ret;
        sort(nums.begin(), nums.end());
        for(i=0;i<static_cast<int>(nums.size()-3);++i){
            if(i>0&&nums[i]==nums[i-1]) continue;
            if(nums[i]+nums[i+1]+nums[i+2]+nums[i+3]>target) break;
            if(nums[i]+nums[nums.size()-1]+nums[nums.size()-2]+nums[nums.size()-3]<target) continue;
            for(j=i+1;j<static_cast<int>(nums.size()-2);++j){
                if(j>i+1&&nums[j]==nums[j-1]) continue;
                if(nums[i]+nums[j]+nums[j+1]+nums[j+2]>target) break;
                if(nums[i]+nums[j]+nums[nums.size()-1]+nums[nums.size()-2]<target) continue;
                tmp = target - nums[i] - nums[j];
                for(k=j+1,l=nums.size()-1;k<l;){
                    if(nums[k]+nums[l] == tmp){
                        ret.push_back(vector<int>{nums[i],nums[j],nums[k],nums[l]});
                        do{++k;}while(nums[k]==nums[k-1]&&k<l);
                        do{--l;}while(nums[l]==nums[l+1]&&k<l);
                    }
                    else if(nums[k]+nums[l] < tmp) ++k;
                    else --l;
                }
            }
        }
        return ret;
    }
};
