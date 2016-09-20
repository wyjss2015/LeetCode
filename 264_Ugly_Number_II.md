#264. Ugly Number II
##Question
Write a program to find the n-th ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.

Note that 1 is typically treated as an ugly number.

##Analysis
* ** 暴力产生丑数：**每一步产生的数是由前面已产生的数分别和2,3,5相乘得到的数中取最小值得到的，假如当前位置i,则当前元素是由（i-1）×3个数值中取最小值得到
* 由上述思想很自然想到利用**小顶堆**进行求解
	1. 初始堆只有一个数1
	2. 每一步从堆中pop出最小数,并判断该数和前面产生的数是否相同，若相同继续pop, 不同则成功产生丑数并转3
	3. 每产生一个数就将该数分别乘2,3,5，得到的三个数push进堆中，转2
* 上述方法由于会产生比需要的个数多的数浪费了时间和空间，因此可以通过限制堆中元素个数，并记录堆中最新的元素是由哪个之前的丑数乘2或3或5产生的，进行优化。。。本方法我只实现前面部分未做优化并不能ac，代码留下等有时间再改动
* 另一种高效的方法就是采用**DP**，总体思路归结起来其实和上面一样，只不过更巧妙的利用了丑数产生的规律，使用三个指针记录当前丑数的产生情况，算法实现上要注意产生和前面最近丑数相同的情况（该方法参考自网络）【[链接](http://www.geeksforgeeks.org/ugly-numbers/)】

##Solution using DP
```
class Solution{
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n);
        dp[0] = 1;
        int idx2, idx3, idx5;
        idx2 = idx3 = idx5 = 0;
        for(int i=1; i<n;){
            int temp = min(dp[idx2]*2,min(dp[idx3]*3, dp[idx5]*5));
            if(temp == dp[idx2]*2){
                if(dp[i-1]!=temp) dp[i++] = temp;
                idx2++;
            }else if(temp == dp[idx3]*3){
                if(dp[i-1]!=temp) dp[i++] = temp;
                idx3++;
            }else{
                if(dp[i-1]!=temp) dp[i++] = temp;
                idx5++;
            }
        }
        return dp[n-1];
    }
};
```

##Solution using heap (NOT AC)
```
class Solution{
public:
    int nthUglyNumber(int n) {
		vector<int> dp;
        if(n==1) return 1;
        vector<int> heap(1,1);
        make_heap(heap.begin(), heap.end(),greater<int>());
        --n;
        int i=0;
        while(n>=0){
            pop_heap(heap.begin(),heap.end(),greater<int>());
            int temp = heap.back();
			if(dp.size()==0||*(dp.end()-1)!=temp){
				dp.push_back(temp);
				--n;
			}
            heap.pop_back();
            heap.push_back(temp*2);
            push_heap(heap.begin(),heap.end(),greater<int>());
            heap.push_back(temp*3);
            push_heap(heap.begin(),heap.end(),greater<int>());
            heap.push_back(temp*5);
            push_heap(heap.begin(),heap.end(),greater<int>());
        }
        return *(dp.end()-1);
    }
};
```