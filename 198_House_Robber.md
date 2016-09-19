#198. House Robber
##Question
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

##Analysis
* 最大独立集问题的特殊情况(只有path结构)
* 使用动态规划求解

##Solution
```
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        else if(nums.size()==1)
            return nums[0];
        vector<int> booking(nums.size());
        booking[0] = nums[0];
        booking[1] = nums[0]>nums[1] ? nums[0] : nums[1];
        
        for(int i=2;i<nums.size();++i)
            booking[i] = booking[i-1]>(booking[i-2]+nums[i]) ? booking[i-1] : booking[i-2]+nums[i];
        return booking[nums.size()-1];
    }
};

```