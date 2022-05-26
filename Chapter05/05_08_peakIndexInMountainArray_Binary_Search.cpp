/*

LeetCode #852. 山形陣列中的最大值 Peak Index in a Mountain Array

A. 題目

如果一個陣列 arr 符合以下條件，就把它叫做「山形陣列」：
    a. arr.length≥3
    b. 存在某個 i，且 0<i<arr.length-1，使得
        arr[0]<arr[1]<⋯<arr[i-1]<arr[i]
        arr[i]>arr[i+1]>⋯>arr[arr.length-1] 

給定一個山形陣列 arr，回傳所有符合條件的 i，使得
    arr[0]<⋯<arr[i-1]<arr[i]>arr[i+1]>⋯>arr[arr.length-1]

B. 出處
https://leetcode.com/problems/peak-index-in-a-mountain-array/


*/

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int lower = 1;
        int upper = arr.size() - 2;
        while(upper >= lower){
            int middle = lower + (upper - lower) / 2;
            if(arr[middle] > arr[middle - 1] && arr[middle] > arr[middle + 1])
                return middle;
            else if(arr[middle] < arr[middle + 1])
                lower = middle + 1;
            else
                upper = middle - 1;
        }
        return -1; 
    }
};