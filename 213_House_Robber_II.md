#213. House Robber II

##Question
Note: This is an extension of House Robber.

After robbing those houses on that street, the thief has found himself a new place for his thievery so that he will not get too much attention. This time, all houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, the security system for these houses remain the same as for those in the previous street.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

##analysis
* 两次调用198题dp算法

##Solution
```
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==0) return 0;
        else if(nums.size()==1) return nums[0];
        vector<int> nums0(nums.begin(),nums.end()-1);
        vector<int> nums1(nums.begin()+1, nums.end());
        int temp0 = helper(nums0);
        int temp1 = helper(nums1);
        if(temp0>temp1) return temp0;
        else return temp1;
    }
    int helper(vector<int>& nums){
        if(nums.size()==0) return 0;
        else if(nums.size()==1) return nums[0];
        vector<int> dp(nums.size());
        
        dp[0] = nums[0];
        dp[1] = nums[0]>nums[1] ? nums[0] : nums[1];
        for(int i=2;i<nums.size();++i)
            dp[i] = dp[i-1]>(dp[i-2]+nums[i]) ? dp[i-1] : (dp[i-2]+nums[i]);
        return dp[nums.size()-1];
    }
};
```