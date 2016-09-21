#231. Power of Two
##Question
Given an integer, write a function to determine if it is a power of two.

##Analysis
* **trick:** n&(n-1)

##Solution
```
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0) return false;
        return !(n&(n-1));
    }
};
```