#46. Permutations
##Question
Given a collection of distinct numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
```
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
```
##Analysis
* Backtracking
* 利用swap可以写出更漂亮的代码

##Solution 1
```
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<int> temp;
        sort(nums.begin(), nums.end());
        int size = nums.size();
        helper(ret, temp, nums, size);
        return ret;
    }
    void helper(vector<vector<int>>& ret, vector<int>& temp, vector<int>& nums, int n){
        if(n==0){
            ret.push_back(temp);
            return;
        }
        int size = nums.size();
        for(int i=0;i<size;++i){
            int tmp = nums[i];
            temp.push_back(tmp);
            nums.erase(nums.begin()+i);
            helper(ret, temp, nums, n-1);
            temp.pop_back();
            nums.push_back(tmp);
            sort(nums.begin(), nums.end());
        }
    }
};
```

##Solution 2
```
class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
	    vector<vector<int> > result;
	    
	    permuteRecursive(num, 0, result);
	    return result;
    }
    
    // permute num[begin..end]
    // invariant: num[0..begin-1] have been fixed/permuted
	void permuteRecursive(vector<int> &num, int begin, vector<vector<int> > &result)	{
		if (begin >= num.size()) {
		    // one permutation instance
		    result.push_back(num);
		    return;
		}
		
		for (int i = begin; i < num.size(); i++) {
		    swap(num[begin], num[i]);
		    permuteRecursive(num, begin + 1, result);
		    // reset
		    swap(num[begin], num[i]);
		}
    }
};
```