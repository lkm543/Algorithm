/*

LeetCode #441. 安排硬幣 Arranging Coins

A. 題目

你有 n 個硬幣，且你想要用這些硬幣來排出一個階梯的形狀。這個階梯有 k 個橫列，第 i 個橫列剛好會有 i 個硬幣，最下面的那個橫列可以不用填滿。

給定一個整數 n，回傳該階梯完整的「橫列」數。

B. 出處
https://leetcode.com/problems/arranging-coins/

*/

class Solution {
    long long int sum(long long int middle){
        return middle * (middle + 1) / 2;
    }
public:
    // k -> k*(k+1)/2
    // (k-1)*k/2 < n < k*(k+1)/2
    int arrangeCoins(int n) {
        int lower = 0;
        int upper = 2 * sqrt(n);
        while(upper > lower){
            int middle = lower + (upper - lower) / 2;
            if(sum(middle) == n)
                return middle;
            else if(sum(middle) > n)
                upper = middle;
            else if(sum(middle) < n)
                lower = middle + 1;
        }
        return lower - 1;
    }
};