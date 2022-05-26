/*

LeetCode #1217. 移動籌碼到同一位置的最小成本 Minimum Cost to Move Chips to The Same Position

A. 題目
總共有 n 個籌碼，position[i] 代表第 i 個籌碼的位置。
目標是移動所有籌碼到同一個位置上，每次動作可以把某個籌碼從 position[i] 移動到其他位置：

a. 移動到 position[i]+2 或 position[i]-2，成本為 0
b. 移動到 position[i]+1 或 position[i]-1，成本為 1

回傳要把所有籌碼移動到同一個位置需要的最小成本。

B. 出處
https://leetcode.com/problems/minimum-cost-to-move-chips-to-the-same-position/

*/

class Solution{
public:
	int minCostToMoveChips(vector<int>& position){
		int len = position.size();
		int odd_sum = 0;
		int even_sum = 0;

		// 計算奇數籌碼數與偶數籌碼數
		// 例如 [2,3,5] 代表共有三個籌碼
		// 第一個籌碼在 2、第二個籌碼在 3、第三個籌碼在 5
		for(int i : position){
			if(i % 2){
				odd_sum++;
			}
            else{
				even_sum++;
            }
		}
		// 回傳兩者中較小者
		return odd_sum < even_sum ? odd_sum : even_sum;
	} // end of minCostToMoveChips
}; // end of Solution
