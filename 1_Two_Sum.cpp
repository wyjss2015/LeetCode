/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

//暴力解法 O(n^2)
int* twoSum(int* nums, int numsSize, int target) {
    int i,j;
    int *indix,*p;
    indix = (int *)malloc(sizeof(int)*2);
    p = indix;
    for(i=0;i<numsSize;i++){
        for(j=i+1;j<numsSize;j++){
            if(target == nums[i] + nums[j]){
                *p = i+1;
                *(++p) = j+1;
                return indix;
            }
        }
    }
}

//双指针O(nlogn) 12ms
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i, j;
        vector<int> data(nums);
        sort(data.begin(), data.end());
        for(i=0,j=data.size()-1;i<j;){
            if(data[i]+data[j]<target) ++i;
            else if(data[i]+data[j]>target) --j;
            else{
                int pos1 = find(nums.begin(), nums.end(), data[i]) - nums.begin();
                nums[pos1] = INT_MAX;
                int pos2 = find(nums.begin(),nums.end(), data[j]) - nums.begin();
                return vector<int>{pos1,pos2};
            }
        }
        return vector<int>();
    }
};

//hash方法
