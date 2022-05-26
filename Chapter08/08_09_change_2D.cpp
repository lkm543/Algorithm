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
		// 陣列大小為 len + 1 個 row
        // amount + 1 個 column
		vector<vector<int>> DP(
            len + 1,
            vector<int>(amount + 1, 0)
        );

		DP[0][0] = 1;

		// 用雙重迴圈逐一填上 DP 的值
		// 不用填第 0 個 row，因為值和預設值 0 相同
		for (int i = 1; i <= len; i++){
			DP[i][0] = 1;  // 第 0 個 column 填上 1

			for (int j = 1; j <= amount; j++){
				// DP[i][j] = DP[i-1][j] + DP[i][j-coins[i-1]]
				// 不使用第 i 種硬幣 + 使用第 i 種硬幣
				DP[i][j] += DP[i-1][j];
				if (j - coins[i - 1] >= 0){
				    DP[i][j] += DP[i][j - coins[i - 1]];
			    }
			} // end of inner for
		} // end of outer for
		// 回傳值中 len 代表考慮使用所有種類的硬幣
		// amount 代表要湊出 amount 元
		return DP[len][amount];
	} // end of change
}; // end of Solution
