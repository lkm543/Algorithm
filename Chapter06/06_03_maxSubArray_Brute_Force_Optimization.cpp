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
		// 儲存每個從開頭開始的區間的和
		int sum_1_to_n[n];
		// 儲存所有區間的和
		int sum[n][n];
		int maximum = -2147483648; // -int_max
		// 先計算每個從開頭開始的區間的元素和，複雜度 O(n)
		for (int i = 0; i < n; i++){
			if (i == 0)
				sum_1_to_n[i] = nums[0];
			else
				sum_1_to_n[i] = sum_1_to_n[i - 1] + nums[i];
		}
		// 利用 [0, finish] 和 [0, start-1] 兩個區間和的差
        // 計算其他區間的元素和，複雜度降到 O(n^2)
		for (int start = 0; start < n; start++){
			for (int finish = start ; finish < n ; finish++){
				// start!=0
				if (start){
					// 這層的複雜度從 O(n) 優化成 O(1)
                    sum[start][finish] = sum_1_to_n[finish] - sum_1_to_n[start - 1];
                }
				// start==0
				else{
                    sum[start][finish] = sum_1_to_n[finish];
                }
			    if (sum[start][finish] > maximum){
				    maximum = sum[start][finish];	
			    }
			}
		}
		return maximum;
	}
};
