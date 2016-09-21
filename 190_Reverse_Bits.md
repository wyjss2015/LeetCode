#190. Reverse Bits
##Question
Reverse bits of a given 32 bits unsigned integer.

For example, given input 43261596 (represented in binary as 00000010100101000001111010011100), return 964176192 (represented in binary as 00111001011110000010100101000000).

Follow up:
If this function is called many times, how would you optimize it?

Related problem: Reverse Integer

##Analysis
* 两边向中间同步进行交换

##Solution
```
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        unsigned int ret=0;
        for(int i=0;i<16;++i){
            unsigned int temp1 = 1<<i;
            unsigned int temp2 = 1<<(31-i);
            if((temp1&n)&&!(temp2&n))
                ret += temp2;
            else if(!(temp1&n)&&(temp2&n))
                ret += temp1;
			else if((temp1&n)&&(temp2&n))
				ret += (temp1+temp2);
        }
        return ret;
    }
};
```