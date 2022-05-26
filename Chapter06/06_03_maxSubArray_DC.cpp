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
		// 取得整數陣列 nums 的長度
		int len = nums.size();

		// 例外處理：陣列中沒有資料，回傳整數最小值
		if (len == 0)
			return -2147483648;
		// 例外處理：陣列中只有一筆資料，回傳該筆資料
		if (len == 1)
			return nums[0];

		// 一般情況
		// 訂出 data_left 和 data_right 的範圍
        // 中間元素的迭代器
        auto middle = nums.begin() + len / 2;
		vector<int> data_left(nums.begin(), middle);
		vector<int> data_right(middle, nums.end());

		// 分成三個子問題處理
		int max_left = maxSubArray(data_left);
		int max_right = maxSubArray(data_right);
		int max_center = maxCrossArray(nums);

        // 回傳最大值
		if (max_left >= max_center &&
            max_left >= max_right)
	        return max_left;
        else if (max_right >= max_center &&
                 max_right >= max_left)
	        return max_right;
        else
	        return max_center;
	} // end of maxSubArray

	int maxCrossArray(vector<int>& nums){
		int len = nums.size();
        int middle = (len - 1) / 2;
		int max_center = nums[middle];
		int index_left = -1, index_right = 1;
        int left_sum = 0, right_sum = 0;
        int max = -2147483648;

		while(middle + index_left >= 0){
			left_sum += nums[middle + index_left];
			if (left_sum > max)
				max = left_sum;
			index_left--;
		}
    
        // 如果往左會變大，就累加
        if(max > 0)
		    max_center += max;
        max = -2147483648;

		while(middle + index_right < len){
			right_sum += nums[middle + index_right];
			if(right_sum > max)
				max = right_sum;
			index_right++;
		}

        // 如果往右會變大，就累加
        if(max > 0)
		    max_center += max;
        
		return max_center;
	} // end of maxCrossArray
}; // end of Solution
