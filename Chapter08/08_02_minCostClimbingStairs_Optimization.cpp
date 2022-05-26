/*

LeetCode #746. 爬階梯的最小成本 Min Cost Climbing Stairs

A. 題目
給定一個整數陣列 cost，cost[i] 是踏到階梯上第 i 階後需付的成本，付出該成本後，就可以選擇再往上爬一或二階。
你可以選擇從 index 0 這階開始爬階梯，或者從 index 1 這階開始。回傳要爬完整個階梯到達上方的最小成本。

B. 出處
https://leetcode.com/problems/min-cost-climbing-stairs/

*/

class Solution{
public:
	int minCostClimbingStairs(vector<int>& cost){
		int len = cost.size();
		int step_1 = cost[0];
		int step_2 = cost[1];
		int step_3;
		cost.push_back(0);

		for (int i = 2; i <= len; i++){
			step_3 = step_1 < step_2 ? step_1 : step_2;
			step_3 += cost[i];

			// 接下來，更新 step_1 和 step_2 的值
			// 使得算下一階時，能用到新的 step_1 和 step_2
			// step_2 -> step_1
			step_1 = step_2;
			// step_3 -> step_2
			step_2 = step_3;
		}
		// 回傳的是迴圈執行完後 step_3 的值
		return step_3;
	} // end of minCostClimbingStairs
}; // end of Solution
