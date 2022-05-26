/*

LeetCode #35. 找尋插入位置 Search Insert Position

A. 題目
給定一個已排序的整數陣列（數字不重複）和目標值，如果目標在陣列中，回傳其索引值，如果不在陣列中，則回傳其應該插入在哪個索引值，才能使陣列仍然符合排序。

B. 出處
https://leetcode.com/problems/search-insert-position/

*/

class Solution{
public:
    int searchInsert(vector<int>& nums, int target){
        int lower = 0;
        int upper = nums.size()-1;
        // 記錄要插入的位置
        int position;
        while(upper >= lower){
            int middle = lower + (upper - lower) / 2;
            if (nums[middle] == target){
                return middle;
            } 
            else if (nums[middle] > target){
                upper = middle - 1;
                position = middle;
            } 
            else {
                lower = middle + 1;
                position = middle + 1;
            }
        } 
        // 沒有找到 target
        return position;
    }
}; 
