/*

LeetCode #583. 字串間的刪除次數 Delete Operation for Two Strings

A. 題目
給定兩字串，請告訴我至少要刪除幾次字元，每次只能刪去一個字元，才可以讓這兩字串的內容完全一致？

B. 出處
https://leetcode.com/problems/delete-operation-for-two-strings/

*/

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1 = word1.length();
        int n2 = word2.length();
        // 宣告一個大小為 (n1 + 1) x (n2 + 1) 的陣列
        // 並初始化為 0
        vector<vector<int>> DP(n1 + 1, vector<int> (n2 + 1, 0));
        // DP[i][0]: 長度 i 的資料要刪幾次才會跟 0 一樣
        // Ans: i 次
        for(int i = 0; i <= n1; i++){
            DP[i][0] = i;
        }
        // DP[0][i]: 長度 i 的資料要刪幾次才會跟 0 一樣
        // Ans: i 次
        for(int i = 0; i <= n2; i++){
            DP[0][i] = i;
        }
        // 依序填表
        for(int i = 1; i <= n1; i++){
            for(int j = 1; j <= n2; j++){
                // 最後一個字元相同
                if(word1[i - 1] == word2[j - 1]){
                    DP[i][j] = DP[i - 1][j - 1];
                }
                // 最後一個字元不相同
                else{
                    DP[i][j] = DP[i - 1][j] < DP[i][j - 1] ? DP[i - 1][j] : DP[i][j - 1];
                    DP[i][j]++;
                }
            }
        }
        return DP[n1][n2];        
    }
};
