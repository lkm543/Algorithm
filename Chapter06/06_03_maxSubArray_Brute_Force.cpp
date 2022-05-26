/*

LeetCode#53. 最大子數列 Maximum Subarray

A. 題目：
給定一個整數陣列 nums，找到其中的連續子陣列，其元素總和為最大，並回傳該元素總和。

B. 題目來源： 
https://leetcode.com/problems/maximum-subarray/ 

*/

class Solution{
public:
	int maxSubArray(vector<int>& nums){
		int n = nums.size();
		// Should use malloc or vector instead;
		int sum[n][n]; 
        // -int_max
		int maximum = -2147483648; 
		// 指定區間開始位置
		for (int start = 0; start < n; start++){
			// 指定區間結束位置
			for (int finish = start ; finish < n; finish++){
				sum[start][finish] = 0;
				// 計算區間的元素和
				for (int k = start; k <= finish; k++){
					sum[start][finish] += nums[k];
				}
				if (sum[start][finish] > maximum){
					maximum = sum[start][finish];
				}
			}
		}
		return maximum;
	}
};
