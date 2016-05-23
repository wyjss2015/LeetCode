class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ret=10000, tmp;
        int i, j, k;
        sort(nums.begin(), nums.end());
        for(i=0;i<nums.size()-2;++i){
            for(j=i+1,k=nums.size()-1;j<k;){
                tmp = nums[i]+nums[j]+nums[k];
                if(abs(ret-target)>abs(tmp-target))
                    ret = tmp;
                tmp<target ? ++j : --k;
            }
        }
        return ret;
    }
};
