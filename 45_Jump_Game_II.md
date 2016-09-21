#45. Jump Game II
##Question
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

For example:
Given array A = [2,3,1,1,4]

The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)

Note:
You can assume that you can always reach the last index.

##Analysis
* 本题在另一道相关题【[55_Jump_Game.md](55_Jump_Game.md)】的本质解法基础上进行扩展
* **思路：**同样维持一个直到当前点所能到达的最远距离变量，此外该变量其实隐藏说明了利用最短步数所能到达的最远距离，在该变量变化时同时对步数进行加一
* **通俗解释：**可以看做这样一个Greedy思考过程：走一步最远到达哪？走两步最远到达哪？。。。。。。

##Solution
```
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int steps = 0;
        int furthest = 0;
        int idx = 0;
        for(int i=0;i<n-1;++i){
            furthest = furthest>i+nums[i] ? furthest : i+nums[i];
            if(idx == i){
                steps++;
                idx = furthest;
                if(furthest>=n-1) return steps;
            }
        }
        return 0;
    }
};
```