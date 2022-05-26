/*

LeetCode #53. 最大子數列 Maximum Subarray

A. 題目
給定一個整數陣列 nums，找到最大子數列（至少包含一個元素）使得其和為最大，並回傳該和。

B. 出處
https://leetcode.com/problems/maximum-subarray/

*/

class Solution{
public:
	int maxSubArray(vector<int>& nums){
		int len = nums.size();
		// 例外處理：只有一個元素時，回傳該元素值
		if(len == 1)
			return nums[0];

		// 開出新陣列 DP
		vector<int> DP(len);
		// DP[0] 與第一個元素的值相同
		DP[0] = nums[0];

		// 算出 DP 陣列中的值
		for (int i = 1; i < len; i++){
			// DP 陣列中前一個值
			int before_now = DP[i - 1];
			// 目前處理的新元素值
			int now = nums[i];
			// 目前處理的元素往左延伸可以得到的最大值
			int add_before = now + before_now;
			// 決定是否往左延伸
			DP[i] = add_before > now ? add_before : now;
		}

		// 負無限大
		int max = -2147483648;
		// 找出 DP 陣列中的最大值
		for (int i = 0; i < len; i++){
			max = max > DP[i] ? max : DP[i];
		}
		return max;
	} // end of maxSubArray
}; // end of Solution
