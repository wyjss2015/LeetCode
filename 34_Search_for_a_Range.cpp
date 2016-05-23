class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ret{-1,-1};
        int i ,j, mid;
        i=0;
        j=nums.size()-1;
        mid=j/2;
        while(i<=j && !(nums[mid]==target&&(mid==0||nums[mid-1]!=target))){
            if(nums[mid]>target||(nums[mid]==target&&mid!=0&&nums[mid-1]==target))
                j = mid - 1;
            else if(nums[mid]<target)
                i = mid + 1;
            mid = (i+j)/2;
        }
        if(i<=j){
            ret[0]=mid;
            if(mid==nums.size()-1||nums[mid+1]!=target){
                ret[1] = mid;
                return ret;
            }
        }
        else
            return ret;
            
        i=0;
        j=nums.size()-1;
        mid=j/2;
        while(i<=j && !(nums[mid]==target&&(mid==nums.size()-1||nums[mid+1]!=target))){
            if(nums[mid]<target||(nums[mid]==target&&mid!=nums.size()-1&&nums[mid+1]==target))
                i = mid + 1;
            else if(nums[mid]>target)
                j = mid - 1;
            mid = (i+j)/2;
        }
        if(i<=j)
            ret[1]=mid;
        return ret;
    }
};
