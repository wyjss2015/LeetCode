#77. Combinations
##Question
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:
```
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
```

##Analysis
* C(n, k) = C(n-1, k-1) + C(n-1, k);

##Solution
```
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ret;
        vector<int> temp;
        helper(ret, temp, n, k);
        return ret;
    }
    void helper(vector<vector<int>> &ret, vector<int> &temp, int n, int k){
        if(n<k) return;
        if(k==0){
            ret.push_back(temp);
            return;
        }
        temp.push_back(n);
        helper(ret, temp, n-1, k-1);
        temp.pop_back();
        helper(ret, temp, n-1, k);
    }
};
```