/*

LeetCode #441. 安排硬幣 Arranging Coins

A. 題目
你有 n 個硬幣，且你想要用這些硬幣來排出一個階梯的形狀。這個階梯有 k 個橫列，第 i 個橫列剛好會有 i 個硬幣，最下面的那個橫列可以不用填滿。
給定一個整數 n，回傳該階梯完整的「橫列」數。

B. 出處
https://leetcode.com/problems/arranging-coins/

*/

class Solution{
    // 避免溢位，用函式計算 middle 層可以放的硬幣數
    long long int sum(long long int middle){
        return middle * (middle + 1) / 2;
    }

public:
    int arrangeCoins(int n){
        int lower = 0;
        // k 超過 2*sqrt(n) 時，k*(k+1)/2 一定超過 n
        // 因此初始的上界 upper 可以取 2*sqrt(n)
        // 若再向下取到 sqrt(2n) 會有邊界處理問題
        int upper = 2 * sqrt(n);
        while (upper > lower){
            int middle = lower + (upper - lower) / 2;
            // middle 層正好放的下 n 個硬幣
            if (sum(middle) == n){
                return middle;
            }
            // middle 層可以放超過 n 個硬幣
            else if (sum(middle) > n){
                upper = middle;
            }
            // middle 層放不下 n 個硬幣
            else if (sum(middle) < n){
                lower = middle + 1;
            }
        } 
        return lower-1;
    } 
}; 
