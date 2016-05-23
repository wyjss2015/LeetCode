class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        while(n>0&&m>0){
            nums1[m+n-1] = (nums1[m-1]>nums2[n-1]) ? nums1[--m] : nums2[--n];
        }
        while(n>0)
            nums1[n-1] = nums2[--n];
    }
};
