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
class Solution{
    // 回傳黃金切割的索引值
    // 也可以選擇不使用 0.382 和 0.618，改用數學算出實際精確值
    int gold_1(int lower, int upper){
        return lower + (upper - lower) * 0.382;
    }
    int gold_2(int lower, int upper){
        return lower + (upper - lower) * 0.618;
    }
public:
    int peakIndexInMountainArray(vector<int>& arr){ 
        // 極值不會出現在開頭或結尾
        // i 從 1 到 arr.size()-2
        int lower = 1;
        int upper = arr.size() - 2;
        int cut_1 = gold_1(lower, upper);
        int cut_2 = gold_2(lower, upper);
        // cut_1 和 cut_2 切出的區間有資料時可以繼續執行
        while (cut_2 > cut_1){
            // 如果極值在 cut_2 左邊
            // cut_2 變為上界           
            // cut_1 變為下一輪的 cut_2
            // 新切出下一輪的 cut_1（區間為原先的 [lower, cut_2]）            
            if (arr[cut_1] > arr[cut_2]){
                upper = cut_2;
                cut_2 = cut_1;
                cut_1 = gold_1(lower, upper);
            }
            // 如果極值在 cut_1 右邊
            // cut_1 變為下界           
            // cut_2 變為下一輪的 cut_1
            // 新切出下一輪的 cut_2（區間為原先的 [cut_1, upper]）
            else {
                lower = cut_1;
                cut_1 = cut_2;
                cut_2 = gold_2(lower, upper);
            }
        }
       // 因為這題不能無限切割下去（索引值必須是整數）
       // 所以上面迴圈只能先限縮 lower 和 upper 的值
       // 仍然要在這個區間內尋找極值
       // 因為極值不會出現在開頭及尾端，要調整 lower 和 upper
        lower = (lower > 0 ? lower : 1);
        upper = (upper < arr.size() - 1 ? 
            upper : arr.size() - 2);
        for (int i = lower; i <= upper; i++){
            if(arr[i] > arr[i - 1] && arr[i] > arr[i + 1])
                return i;
        }
        return -1;
    } 
};
