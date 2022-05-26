/*

LeetCode #343. 拆分整數 Integer Break

A. 題目
給定一個整數 n，將它拆分為 k 個正整數的和，其中 k≥2。找到可使這些拆分出的整數乘積最大的拆分方法，並回傳該乘積。

B. 出處
https://leetcode.com/problems/integer-break/

*/

class Solution{
public:
	int integerBreak(int n){
        // 儲存中間結果的陣列
		vector<int> DP(n + 1, 1);
        
		for (int i = 2; i < n + 1; i++){
			int max = -2147483648;
			for (int j = 1; j < i; j++){
				// i - j 繼續拆分與不拆分兩者間，取較大的
				int now = j * DP[i - j] > j * (i - j) ? 
                            j * DP[i - j] : j * (i - j);
				max = now > max ? now : max;
			}
            // 儲存得到的結果
            DP[i] = max;
		}
		return DP[n];
	} // end of integerBreak
}; // end of Solution
