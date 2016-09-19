#53. Maximum Subarray
##Question
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
the contiguous subarray [4,-1,2,1] has the largest sum = 6.

##Analysis
* 分治
* 时间复杂度O(nlogn)

##solution
```
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        return helper(nums,0,nums.size()-1);
    }
    int helper(vector<int>& nums, int l, int r){
        if(l>r)
            return INT_MIN;
        if(l==r)
            return nums[l];
        int mid = (l+r)/2;
        int leftMax = helper(nums, l, mid);
        int rightMax = helper(nums, mid+1, r);
        
        int temp3 = nums[mid]>nums[mid+1] ? nums[mid] : nums[mid+1];
        int temp1,temp2, sum=0;
        int temp;
        temp1 = temp2 = INT_MIN;
        for(int i=mid;i>=l;--i){
            sum += nums[i];
            if(sum>temp1)
                temp1 = sum;
        }
        sum = 0;
        for(int i=mid+1; i<=r; ++i){
            sum += nums[i];
            if(sum > temp2)
                temp2 = sum;
        }
        temp1 = temp1+temp2;
        if(temp1>temp3)
            temp = temp1;
        else
            temp = temp3;
        
        if(temp>=leftMax&&temp>=rightMax)
            return temp;
        else if(leftMax>=temp&&leftMax>=rightMax)
            return leftMax;
        else
            return rightMax;
    }
};
```

##analysis2
* DP
	1. 将原始最优解问题降解成问题（maxSubArray(A[], i)为A[0:i]的最大连续子数组，包含最后一元素i）
	2. maxSubArray(A[], i)满足DP的最优子问题性质
	3. 原始问题的最优解在maxSubArray(A[], i)，i属于[0,n]，中的最大值
* 时间复杂度O(n)

##Solution2
```
class Solution{
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp(nums.size(),0);
        int max = nums[0];
        dp[0] = nums[0];
        for(int i=1;i<nums.size();++i){
            dp[i] = (dp[i-1]>0 ? dp[i-1] : 0) + nums[i];
            if(max<dp[i]) max = dp[i];
        }
        return max;
    }
};
```