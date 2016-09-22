#47. Permutations II
##Question
Given a collection of numbers that might contain duplicates, return all possible unique permutations.

For example,
[1,1,2] have the following unique permutations:
```
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]
```

##Analysis
* backtracking
* **关键点：**保证每层的所有递推调用没有重复，即保证循环中递推调用前加入当前层的元素都不一样
* **trick:** 事先将序列排序，这样在检查不同时只需要考虑上一个元素，不需要遍历前面使用过的所有元素

##Solution
```
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<bool> used(nums.size(), false);
        vector<int> cur(nums.size());
        sort(nums.begin(), nums.end());
        helper(ret, nums, used, cur, 0);
        return ret;
    }
    void helper(vector<vector<int>> &ret, vector<int>& nums, vector<bool> &used, vector<int>& cur, int n){
        if(n==nums.size()){
            ret.push_back(cur);
            return;
        }
        int last = INT_MAX;
        for(int i=0;i<nums.size();++i){
            if(!used[i]&&last!=nums[i]){
                last = nums[i];
                used[i] = true;
                cur[n] = nums[i];
                helper(ret, nums, used, cur, n+1);
                used[i] = false;
            }
        }
    }
};
```