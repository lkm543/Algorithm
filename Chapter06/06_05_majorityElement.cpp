/*

LeetCode#169 多數元素 Majority Element

A. 題目
給定一個長度為 n 的整數陣列 nums，回傳「多數元素」。這裡多數元素指的是「出現多於 ⌊n/2⌋ 次的元素」。測資中的每個陣列中都存在一個多數元素。

B. 出處：
https://leetcode.com/problems/majority-element/

*/

class Solution{
	// 傳入整數陣列、下界的索引值與上界的索引值
	// 回傳介於傳入下界與上界間的區間中的多數元素
	int majority_range(
            vector<int>& nums, int lower, int upper
        )
    {
		// 邊界處理：傳入區間已經縮小到沒有值
		if (lower==upper)
			return nums[lower];

		// 一般情形
		// 分成左右兩個子陣列遞迴處理
		int middle = lower + (upper - lower) / 2;
		int left_major =
            majority_range(nums, lower, middle);
		int right_major =
            majority_range(nums, middle + 1, upper);

		// 比較左邊與右邊多數元素
		// 相同時任意回傳一邊
        if (left_major == right_major)
			return right_major;

		// 不同時，回傳出現次數較多者
		int left_count = 0, right_count = 0;
		for (int i = lower; i <= middle; i++){
			if (nums[i]==left_major)
			    left_count++;
		}
		for (int i = middle + 1; i <= upper; i++){
			if (nums[i] == right_major)
			    right_count++;
		}
	    return left_count > right_count ? 
            left_major : right_major;
	}

public:
    int majorityElement(vector<int>& nums){
        // 把整個 nums 陣列傳入函式處理
        return majority_range(nums, 0, nums.size()-1);
    }
};
