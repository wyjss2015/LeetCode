#134. Gas Station
##Question
There are N gas stations along a circular route, where the amount of gas at station i is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.

Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.

Note:
The solution is guaranteed to be unique.

##Analysis
* **思路：**
	1. 假如从A到不了B（B为A第一个到不了的站），那么A和B之间的站也不能到达B
	2. gas总量大于等于cost总量，则一定有解
* **proof:**
	1. **反证法：**假设A和B之间某点C能到达B，因为B是A第一个不能到达的点，所以A能到达C，从而A能到达B，这与前提A到不了B矛盾，得证。
	2. 在证明之前先介绍算法，再进行证明
		* **算法**：初始起点start为索引0，假设循环到时， 从0到i的局部gas总量<局部cost总量，那么起点start肯定在i之后,所以起点start重置为i+1,循环结束，假如总体gas总量>=局部cost总量，则返回起点start的值。
		* 根据算法可以将整个圈切分成若干部分，其中每部分的起点都曾被置为start值，假设根据索引分别记为(0,a),(a+1,b),(b+1,c),...,(i,j),...,(s,n-1),s可以看做是算法最终返回的结果。
			* **反证法：**
				1. 假设总体gas>=总体cost并且不存在解。则不妨假设存在(i,j)使得gas(s,n-1)-cost(s,n-1)+gas(0,a)-cost(0,a)+...+gas(i,j)-cost(i,j)<0
				2. 根据算法除gas(s,n-1)>=cost(s,n-1)外，其他局部gas<cost， 如gas(i,j)<cost(i,j)
				3. 综上得出总体gas<总体cost，与假设矛盾，得证。

##Solution
```
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start = 0;
        int local = 0;
        int total = 0;
        for(int i=0;i<gas.size();++i){
            local += (gas[i]-cost[i]);
            if(local < 0){
                total += local;
                start = i+1;
                local = 0;
            }
        }
        total += local;
        return total>=0 ? start : -1;
    }
};
```