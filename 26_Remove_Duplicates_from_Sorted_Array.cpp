class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int>::size_type i, j;
        if(nums.size()==0)
            return 0;
        for(i=0,j=0;i<nums.size();++i){
            if(nums[j]==nums[i])
                continue;
            else{
                nums[++j] = nums[i];
            }
        }
        return j+1;
    }
};
