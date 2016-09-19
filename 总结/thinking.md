#刷题感悟
##DP
###题型两种
1. 原始问题直接构造最优子结构
2. 先降解，降解后的问题可以构造最优子结构求解，再return 降解后问题中最优的解
	* 如原始问题经常降解成问题（满足当前点作为最后节点包含其中）
	* 如第300题的[Longest_Increasing_Subsequence](../300_Longest_Increasing_Subsequence.md)和53题的[Maximum_Subarray](../53_Maximum_Subarray.md)