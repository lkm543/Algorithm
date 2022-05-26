/*

LeetCode #322 硬幣找零 Coin Change
注意本題如果使用貪婪演算法來解決，會得到「錯誤」的答案，但建議你仍可以試著先寫出對應的貪婪解法，並思考為何會出錯，下一章介紹動態規劃法就可以順利解決這個問題。

A. 題目
給定一個整數陣列 coins 代表各種硬幣的面額，與一個整數 amount 代表要達到的總額。

回傳「要達到該總額最少需要的硬幣個數」，如果根據給定的各種硬幣面額無法剛好達到該總額，回傳 -1。每種硬幣的可用個數沒有上限。

B. 出處
https://leetcode.com/problems/coin-change/

*/

class Solution{
public:
	int coinChange(vector<int>& coins, int amount){
		// 例外處理：amount 為 0
		if (amount == 0)
			return 0;
		// 一般情形
		// 把硬幣面額從大到小排
        sort(coins.begin(), coins.end(), greater<int>());
		int coin_count = 0;
		int len = coins.size();

		// 從面額最大的硬幣開始盡量貼近總額
		for (int i = 0; i < len; i++){
			// 當前處理的面額
			int value = coins[i];
			// 目前面額硬幣最多可以使用的個數
			// 例如總額為 240 時，可以使用四個 50 塊
			coin_count += amount / value;
			// 更新 amount
			// 例如用了四個 50 塊後，amount 從 240 更新為 40
			amount %= value;
			// 可以找開時，回傳硬幣數目
			if (amount == 0)
				return coin_count;
		} // end of for
        return -1;
	} // end of coinChange
}; // end of Solution
