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

		// 記錄到達每一階的最小成本
		// 因為在最後面加上一階，所以長度是 len + 1
		vector<int> Step(len + 1);

		// 前兩階的最小成本直接取該階需付的成本
		Step[0] = cost[0];
		Step[1] = cost[1];

		// 把加在最後面的一階成本設為 0
		cost.push_back(0);
	
		for (int i = 2; i <= len; i++){
			// 選擇前兩階中成本較小者，再加上該階自己的成本
			Step[i] = (Step[i - 1] < Step[i - 2] ?
                       Step[i - 1] : Step[i - 2])
                       + cost[i]; 
		}
		return Step[len];
	} // end of minCostClimbingStairs
}; // end of Solution
