#215. Kth Largest Element in an Array
##Question
Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

For example,
Given [3,2,1,5,6,4] and k = 2, return 5.

Note: 
You may assume k is always valid, 1 ≤ k ≤ array's length.

##Analysis
* 分治
* 本题我利用quicksort的partition函数

##Solution
```
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return helper(nums, 0, nums.size()-1, k);
    }
    int helper(vector<int>& nums, int l, int r, int k){
        if(l==r) return nums[l];
        pivot(nums, l, r);
        int i,j;
        for(i=l;i<r&&nums[i]>nums[r];++i)
            ;
        for(j=i,i-=1;j<r;++j)
            if(nums[j]>nums[r]) swap(nums, ++i, j);
        swap(nums, ++i, r);
        
        int cnt = i-l+1;
        if(cnt>k) return helper(nums, l, i-1, k);
        else if(cnt<k) return helper(nums, i+1, r, k-cnt);
        else return nums[i];
    }
    void swap(vector<int>& nums, int a, int b){
        int temp = nums[a];
        nums[a] = nums[b];
        nums[b] = temp;
    }
    void pivot(vector<int>& nums, int l, int r){
        int m = (l+r)/2;
        if((nums[l]>=nums[m]&&nums[l]<=nums[r])||(nums[l]>=nums[r]&&nums[l]<=nums[m]))
            swap(nums, l, r);
        else if((nums[m]>=nums[r]&&nums[m]<=nums[l])||(nums[m]>=nums[l]&&nums[m]<=nums[r]))
            swap(nums, m, r);
    }
};
```