#80. Remove Duplicates from Sorted Array II
##Question
Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array nums = [1,1,1,2,2,3],

Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3. It doesn't matter what you leave beyond the new length.

##Analysis
* 方法一：设计个局部计数器
* 方法二：和已产生的新数组的倒数第二个数比较（十分精简的解法）

##Solution 1
```
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0) return 0;
        int i,j,cnt;
        for(i=0,j=1,cnt=0;j<nums.size();++j){
            if(nums[j]==nums[j-1]&&!cnt){
                cnt = 1;
                nums[++i] = nums[j];
            }
            else if(nums[j]!=nums[j-1]){
                cnt = 0;
                nums[++i] = nums[j];
            }
        }
        return i+1;
    }
};
```
##Solution 2
```
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0;
        for(int j=0;j<nums.size();++j)
            if(i<2||nums[j]>nums[i-2])
                nums[i++] = nums[j];
        return i;
    }
};
```