#136. Single Number
##Question
Given an array of integers, every element appears twice except for one. Find that single one.

##Analysis
* hash
* xor

##Solution
```
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int temp = 0;
        for(int &a: nums)
            temp ^= a;
        return temp;
    }
};
```