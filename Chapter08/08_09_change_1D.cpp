/*

LeetCode #518. 找錢問題2 Coin Change 2

A. 題目
給定一個整數陣列 coins 代表每種硬幣的面額，與一個整數 amount 代表要找的金額。

回傳可以組成該金額的方法數，如果沒有任何方法可以組成該金額，回傳 0。
假設每種面額的硬幣數不限。

B. 出處
https://leetcode.com/problems/coin-change-2/

*/

class Solution{
public:
	int change(int amount, vector<int>& coins){
		int len = coins.size();
		vector<int> DP(amount+1,0);
		DP[0] = 1;
        
		for (int coin:coins){
			// i 要從 coin 開始，避免 i-coin<0 的情況
			for (int i = coin; i <= amount; i++){
				DP[i] += DP[i - coin];
			}
		} // end of for
		return DP[amount];
	} // end of change
}; // end of Solution
