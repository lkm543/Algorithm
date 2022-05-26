/*

A. 題目

給定兩個已排序成升冪的整數陣列 nums1 與 nums2，且其長度分別為 m 與 n，請把這兩個陣列合併至 nums1，合併後須讓 nums1 內的資料亦成升冪排列。

為了順利合併，一開始 nums1 向量的長度即為 m+n，其中前 m 筆資料為 nums1 的資料，後面 n 筆資料被設定成 0 可以忽略。

B. 出處
https://leetcode.com/problems/merge-sorted-array/

*/

class Solution {
public:
    void merge(vector<int>& nums1, int m, 
                vector<int>& nums2, int n) 
    {
        vector<int> data_1 = nums1;
        // i, j代表 nums1, nums2 各處理到第幾個元素
        int i = 0, j = 0;
        // k 代表合併到第幾個元素
        int k = 0;
        while(i < m && j < n){
            // nums2[j] 的資料較小，把 nums2[j] 放入 nums1
            if(data_1[i] > nums2[j]) {
                nums1[k] = nums2[j];
                j++;
            }
            // data_1[i] 的資料較小，把 data_1[i] 放入 nums1
            else{
                nums1[k] = data_1[i];
                i++;
            }
            k++;
        }
        // 如果 data_1 還剩資料
        while(i < m){
            nums1[k] = data_1[i];
            i++;
            k++;
        }
        // 如果 nums2 還剩資料
        while(j < n){
            nums1[k] = nums2[j];
            j++;
            k++;
        }
    }
};
