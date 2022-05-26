/*

LeetCode #300. 最長遞增子序列 Longest Increasing Subsequence

A. 題目
給定一陣列，從中保留先後順序並挑選出一序列，使序列內的內容為嚴格遞增，並求此遞增子序列的最大可能長度。

B. 出處
https://leetcode.com/problems/longest-increasing-subsequence/

*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len = nums.size();
        // 把動態規劃陣列初始化為無限大
        // DP[i]:長度為 i 的最大遞增子序列的最後數字
        vector<int> DP(len + 1, 2147483647);
        DP[0] = -2147483648;
        for (int data : nums) {
            // 利用二分搜尋法找出 data 的 lower bound
            auto target = lower_bound(
                DP.begin(), DP.end(), data
            );
            *target = data;
        }
        // 找出無限大出現在最左邊的哪個位置
        auto result = lower_bound(
            DP.begin(), DP.end(), 2147483647
        );
        // 該位置跟 vector 的起點距離再 - 1即是所求
        return result - DP.begin() - 1;
    }
};
