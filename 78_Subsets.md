#78. Subsets
##Question
Given a set of distinct integers, nums, return all possible subsets.

Note: The solution set must not contain duplicate subsets.

For example,
If nums = [1,2,3], a solution is:
```
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
```

##Analysis
* backtracking
* bit manipulation

##Solution 1
```
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<int> temp;
        helper(ret, nums, temp, 0);
        return ret;
    }
    void helper(vector<vector<int>>&ret, vector<int>& nums, vector<int>& temp, int n){
        if(n==nums.size()){
            ret.push_back(temp);
            return;
        }
        temp.push_back(nums[n]);
        helper(ret, nums, temp, n+1);
        temp.pop_back();
        helper(ret, nums, temp, n+1);
    }
};
```
##Solution 2
```
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = 1;
        n <<= nums.size();
        vector<vector<int>> ret(n);
        for(int i=0;i<nums.size();++i){
            for(int j=0;j<n;++j)
                if((j>>i)&1) ret[j].push_back(nums[i]);
        }
        return ret;
    }
};
```