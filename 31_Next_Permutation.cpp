class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size()==1) return;
        vector<int> subNums(nums.begin()+1, nums.end()), tmpNums(nums.begin()+1, nums.end());
        sort(tmpNums.begin(), tmpNums.end());
        reverse(tmpNums.begin(), tmpNums.end());
        if(tmpNums == subNums){
            int maxval = max(nums[0], tmpNums[0]);
            if(nums[0] == maxval)
                reverse(nums.begin(), nums.end());
            else{
                int i, tmp;
                for(i=0;i<tmpNums.size()&&tmpNums[i]>nums[0];++i)
                    ;
                tmp = nums[0];
                nums[0] = nums[i];
                nums[i] = tmp;
                sort(nums.begin()+1, nums.end());
            }
        }else{
            nextPermutation(subNums);
            for(int i=0;i<subNums.size();++i)
                nums[i+1] = subNums[i];
        }
    }
};

//Solution 2 O(n)
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i, j, tmp;
        for(i=nums.size()-2;i>=0&&nums[i+1]<=nums[i];--i)
            ;
        if(i<0) reverse(nums.begin(), nums.end());
        else{
            for(j=i+1;j<nums.size()&&nums[j]>nums[i];++j)
                ;
            --j;
            tmp = nums[i];
            nums[i] = nums[j];
            nums[j] = tmp;
            reverse(nums.begin()+i+1, nums.end());
        }
    }
};
