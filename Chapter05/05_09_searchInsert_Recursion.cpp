/*

LeetCode #35. 找尋插入位置 Search Insert Position

A. 題目
給定一個已排序的整數陣列（數字不重複）和目標值，如果目標在陣列中，回傳其索引值，如果不在陣列中，則回傳其應該插入在哪個索引值，才能使陣列仍然符合排序。

B. 出處
https://leetcode.com/problems/search-insert-position/

*/

class Solution{
    // 使用二分搜尋法
    int binary_search(vector<int>& nums, int lower, int upper, int target){
        // 沒有找到時，回傳應該插入的位置 lower
        if (upper < lower)
            return lower;
        int middle = lower + (upper - lower) / 2;
        // 比較 nums[middle] 與 target 的大小
        if (nums[middle] == target){
            return middle;
        }
        else if (nums[middle] > target){
            return binary_search(nums, lower, middle-1, target);
        }
        else {
            return binary_search(nums, middle+1, upper, target);
        }
    }

public:
    int searchInsert(vector<int>& nums, int target){
        // 回傳二分搜尋的結果
        return binary_search(nums, 0, nums.size()-1, target);
    }
};
