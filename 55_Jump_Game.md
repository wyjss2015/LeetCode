#55. Jump Game
##Question
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return true.

A = [3,2,1,0,4], return false.

##Analysis
* 从后向前，不断缩小问题规模，也即缩小最右边界
* 通俗解释：
| 0 | 1 | 2 | ... | i | i+1 | i+2 | ... | n-2 | n-1 |
|---|---|---|-----|---|-----|-----|-----|-----|-----|
| # | # | # | ... | # |false|true | ... | true| end|
|||||||bound|||||
	1. true代表能到达end， false代表不能到达
	2. 假如当前循环到索引i, 只要判断i是否能到大i+2就行，因为只要能到i+2,接下来从i+2就能到达end
* 另一种**更本质的解法**：维持从前面所有点所能到达的最远距离的变量【[参考链接](https://discuss.leetcode.com/topic/19931/6-line-java-solution-in-o-n)】
* 另一道相关的题【[45_Jump_Game_II.md](45_Jump_Game_II.md)】
	
##Solution
```
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int bound = nums.size()-1;
        for(int i=n-2;i>=0;--i)
            if(nums[i]+i>=bound) bound = i;
        if(bound == 0) return true;
        return false;
    }
};
```