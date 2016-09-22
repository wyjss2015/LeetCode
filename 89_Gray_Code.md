#89. Gray Code
##Question
The gray code is a binary numeral system where two successive values differ in only one bit.

Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.

For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:
```
00 - 0
01 - 1
11 - 3
10 - 2
```
Note:
For a given n, a gray code sequence is not uniquely defined.

For example, [0,2,3,1] is also a valid gray code sequence according to the above definition.

For now, the judge is able to judge based on one instance of gray code sequence. Sorry about that.

##Analysis
* 递推
* 第n轮的元素由到第n-1轮产生的所有元素逆序并把这些元素第n为bit置1得到

##Solution
```
class Solution {
public:
    vector<int> grayCode(int n) {
        if(n==0) return vector<int>(1,0);
        vector<int> ret;
        helper(ret, n);
        return ret;
    }
    void helper(vector<int> &ret, int n){
        if(n==1){
            ret = vector<int>({0,1});
            return;
        }
        helper(ret, n-1);
        int temp = 1<<(n-1);
        int size = ret.size();
        for(int i=size-1;i>=0;--i)
            ret.push_back(ret[i]+temp);
    }
};
```