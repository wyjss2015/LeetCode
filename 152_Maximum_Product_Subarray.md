#152. Maximum Product Subarray
##Question
Find the contiguous subarray within an array (containing at least one number) which has the largest product.

For example, given the array [2,3,-2,4],
the contiguous subarray [2,3] has the largest product = 6.

##Analysis
* DP 基本同求最大和子数组，只不过每步维护两个累计量，最大和最小，因为如果当前元素是负数乘以最小可能变最大，但我没想到比较好的处理0元素和初始化的情况。。。所以转向其他思路
* 本题代码比较凌乱，思路如下
	1. 根据数组中的0元素将数组分成若干连续子数组（问题的解一定在这若干子数组中产生）
	2. 对于每一片段（不包含0），将两两负数间的所有正数相乘得到新数组，同时计算负数的个数
		* 例如 [1,2,-2,3,4,-5,2]->[2,-2,12,-5,2]， 负数个数为2
	3. 对于每一片段的到的新数组，如果负数个数为偶数，则该片段最大乘积为所有数相乘；否则负数个数为奇数，则最大乘积一定是倒数第一个负数前所有数的乘积，或者第一个负数后所有数的乘积

##Solution
```
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        int max = INT_MIN;
        int start = 0;
        nums.push_back(0);
        for(int i=0;i<nums.size();++i){
            if(nums[i]==0){
                vector<int> tempNums(nums.begin()+start, nums.begin()+i);
                int temp = helper(tempNums);
                max = max>temp?max:temp;
                start = i+1;
            }
        }
        return max;
    }
    int helper(vector<int>& nums){
        if(nums.size()==0) return 0;
        vector<int> temp;
        int m = 1;
        int cnt = 0;
        int flag = 0;
        for(int i=0;i<nums.size();++i){
            if(nums[i]>0){
                m *= nums[i];
                flag = 1;
            }
            else{
                if(flag == 1) temp.push_back(m);
                temp.push_back(nums[i]);
                m = 1;
                flag = 0;
                ++cnt;
            }
        }
        if(flag == 1) temp.push_back(m);
        
        if(cnt%2==0){
            int x = 1;
            for(auto &v: temp) x *= v;
            return x;
        }else{
            if(temp.size()==1) return 0;
            int x = 1;
            int y = 1;
            int i,j;
            for(i=0,j=0;i<temp.size()&&j<cnt;++i){
                if(temp[i]<0) ++j;
                if(j<cnt)
                    x *= temp[i];
            }
            
            for(i=temp.size()-1,j=0;i>=0&&j<cnt;--i){
                if(temp[i]<0) ++j;
                if(j<cnt)
                    y *= temp[i];
            }
            return x>y?x:y;
        }
    }
};
```