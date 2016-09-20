#169. Majority Element
##Question
Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.

##Analysis
* 很简单的一题，我使用hash法
* 该题存在时间O(N)空间O(1)很巧妙的解法moore voting algorithm
* 有人总结了6种实现的方法【[链接](https://discuss.leetcode.com/topic/17446/6-suggested-solutions-in-c-with-explanations)】

##Solution
```
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> hash;
        int n = nums.size();
        for(auto &a: nums)
            if(++hash[a]>n/2)
                return a;
        return 0;
    }
};
```

