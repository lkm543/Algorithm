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
    int gold_1(int lower,int upper){
        return lower + (upper - lower) * 0.382;
    }
    int gold_2(int lower,int upper){
        return lower + (upper - lower) * 0.618;
    }
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int lower = 1;
        int upper = arr.size() - 2;
        int cut_1 = gold_1(lower,upper);
        int cut_2 = gold_2(lower,upper);
        while(cut_2 > cut_1){
            if(arr[cut_1] > arr[cut_2]){
                upper = cut_2;
                cut_2 = cut_1;
                cut_1 = gold_2(lower,cut_2);
            }
            else{
                lower = cut_1;
                cut_1 = cut_2;
                cut_2 = gold_1(cut_1,upper);
            }
        }
        for(int i = lower;i <= upper; i++){
            if(arr[i] > arr[i - 1] && arr[i] > arr[i + 1])
                return i;
        }
        return -1;
    }
};