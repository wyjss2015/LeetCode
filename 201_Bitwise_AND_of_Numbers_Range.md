#201. Bitwise AND of Numbers Range
##Question
Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.

For example, given the range [5, 7], you should return 4.
##Analysis
* 某个范围内的数[m,n]，从二进制角度看可以看成前面有一部分相同，后面一部分变化
* 只要m!=n，该范围内末尾bit一定存在零，因为该范围内一定存在偶数，而偶数的末尾为0，

##Solution
```
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int temp = 1;
        while(m!=n){
            m >>= 1;
            n >>= 1;
            temp <<= 1;
        }
        return m*temp;
    }
};
```