/*

LeetCode #278. 第一個錯誤版本 First Bad Version
A. 題目

你是一個產品經理，且正在帶領一個團隊開發新產品，但最新版本的產品無法通過品管測試。因為每個版本都是修改先前的版本而成，所以只要有一個版本發生錯誤，後面的每個版本也都會是錯的。

假設有 n 個版本 [1, 2,..., n]，而你想找到第一個發生錯誤的版本。有一個 API 會根據傳入的版本回傳該版本是否錯誤：bool isBadVersion(version)。

設計一個函式來找到第一個錯誤的版本，並最小化呼叫該 API 的次數。

B. 出處
https://leetcode.com/problems/first-bad-version/

*/

class Solution {
public:
    int firstBadVersion(int n) {
        int lower = 0;
        int upper = n;
        while(lower <= upper){
            int middle = lower + (upper - lower) / 2;
            bool bad = isBadVersion(middle);
            if(bad)
                upper = middle - 1;
            else
                lower = middle + 1;
        }
        return lower;
    }
};