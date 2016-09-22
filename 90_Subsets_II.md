#90. Subsets II
Given a collection of integers that might contain duplicates, nums, return all possible subsets.

Note: The solution set must not contain duplicate subsets.

For example,
If nums = [1,2,2], a solution is:
```
[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
```

##Analysis
* **区别：**
	1. [78_Subsets.md](78_Subsets.md)中每层判断元素有无，即元素出现0或1次
	2. 本题中假设元素重复3次， 则每层判断元素出现0，1,2或3次

##Solution
```
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ret;
        unordered_map<int,int> record;
        vector<int> nums2;
        for(auto &a: nums){
            if(!record.count(a))
                nums2.push_back(a);
            ++record[a];
        }
        vector<int> temp;
        int size = nums2.size();
        helper(ret, temp, nums2, record, 0, size);
        return ret;
    }
    void helper(vector<vector<int>> &ret, vector<int> &temp, vector<int> nums2, unordered_map<int,int>&record, int n, int size){
        if(n==size){
            ret.push_back(temp);
            return;
        }
        helper(ret, temp, nums2, record, n+1, size);
        for(int i=0;i<record[nums2[n]];++i){
            temp.push_back(nums2[n]);
            helper(ret, temp, nums2, record, n+1, size);
        }
        for(int i=0;i<record[nums2[n]];++i)
            temp.pop_back();
    }
};
```