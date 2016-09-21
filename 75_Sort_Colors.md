#75. Sort Colors
##Question
Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note:
You are not suppose to use the library's sort function for this problem.

##Analysis
* quickSort的partition函数的扩展，基本相同

##Solution
```
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int r, w, b;
        w = b = 0;
        for(int i=0;i<nums.size();++i){
            if(nums[i]==0){
                int temp = nums[i];
                nums[i] = nums[b];
                nums[b++] = nums[w];
                nums[w++] = temp;
            }else if(nums[i]==1){
                int temp = nums[i];
                nums[i] = nums[b];
                nums[b++] = temp;
            }
        }
    }
};
```