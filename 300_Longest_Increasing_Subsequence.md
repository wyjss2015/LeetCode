#300. Longest Increasing Subsequence
##Question
Given an unsorted array of integers, find the length of longest increasing subsequence.

For example,
Given [10, 9, 2, 5, 3, 7, 101, 18],
The longest increasing subsequence is [2, 3, 7, 101], therefore the length is 4. Note that there may be more than one LIS combination, it is only necessary for you to return the length.

Your algorithm should run in O(n2) complexity.

**Follow up:** Could you improve it to O(n log n) time complexity?

##Analysis
* DP
	1. reduce
	2. 子问题（A[i]即包含当前最后元素i的最唱增长序列长度）
	3. return max(A[i]) i属于0...n-1
* 存在O(nlogn)[解法](http://www.geeksforgeeks.org/longest-monotonically-increasing-subsequence-size-n-log-n/)

##Solution
```
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        if(n==1) return 1;
        vector<int> dp(n);
        dp[0] = 1;
        int max=0;
        for(int i=1;i<n;++i){
            int max1=0;
            for(int j=i-1;j>=0;--j)
                if(nums[j]<nums[i]&&max1<dp[j]) max1 = dp[j];
            ++max1;
            dp[i] = max1;
            max = max>max1?max:max1;
        }
        return max;
    }
};
```