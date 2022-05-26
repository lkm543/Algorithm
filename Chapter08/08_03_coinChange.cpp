/*

LeetCode #322. 找錢問題 Coin Change

A. 題目
給定一個整數陣列 𝑐𝑜𝑖𝑛𝑠 代表不同面額的硬幣，與一個整數 𝑎𝑚𝑜𝑢𝑛𝑡 代表要找的金額。回傳要組成該金額最少需要的硬幣枚數，如果給定的硬幣面額無法組成該要找的金額，回傳 -1。假設每種硬幣使用的數量不受限制。

B. 出處
https://leetcode.com/problems/coin-change/

*/

class Solution{
public:
    int coinChange(vector<int>& coins, int amount){
		// 儲存 n 元需要最少硬幣枚數的陣列
		// 初始值設定為 -1，用來判斷是否算過
		vector<int> min_coin(amount + 1, -1);
        min_coin[0] = 0;

        // 從 n = 1 開始往後算到 amount
		for (int i = 1; i <= amount; i++){
			// min_coin[i] =
            // min(
            //	min_coin[i - coins[0]],
            //	min_coin[i - coins[1]],
            //	min_coin[i - coins[2]],
            //	...
            // ) + 1
			// int_max, C++ 中常用來代表無限大
            int min = 2147483647;
            // 目前這個 min_coin[current] 的值
            int coin_now;

			for(int coin : coins){
				// 除了最後一枚 coin 外，要找的金額
				int current = i - coin;
                
                // i - coin < 0，沒有這種找法
                // coin_now 設為最大值，確保 min 不被改變
				if(current < 0)
	                coin_now = 2147483647;
                // i - coin >= 0，可以找找看
				else{
                    // 如果此時沒辦法找開
                    if (min_coin[current] == -1)
                        coin_now = 2147483647;
                    // 可以找開
                    else
                        coin_now = min_coin[current];
                }
                // 取最小的硬幣數
                min = coin_now < min ? coin_now : min;
			}

            // 如果 min 還是初始值，代表無法找開，回傳 -1
            if(min == 2147483647){
                min_coin[i] = -1;
            }
            else{
                // 否則是 min 枚硬幣加上最後那枚
                min_coin[i] = min + 1;
            }
		} // end of for
	    return min_coin[amount];
	} // end of coinChange
}; // end of Solution
